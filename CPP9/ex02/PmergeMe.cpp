#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <ctime>

/* ************************************************************************** */
/*                              Canonical form                                */
/* ************************************************************************** */

PmergeMe::PmergeMe() : _comparisons(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _comparisons(other._comparisons) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		_comparisons = other._comparisons;
	return *this;
}

PmergeMe::~PmergeMe() {}

unsigned long PmergeMe::getComparisons() const { return _comparisons; }

/* ************************************************************************** */
/*                                  Helpers                                   */
/* ************************************************************************** */

// Every comparison between two VALUES goes through here, so we can count them.
bool PmergeMe::lessThan(int a, int b)
{
	++_comparisons;
	return a < b;
}

// Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, ...
size_t PmergeMe::jacobsthal(size_t k)
{
	size_t prev = 0;
	size_t curr = 1;
	if (k == 0)
		return 0;
	for (size_t i = 1; i < k; ++i)
	{
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return curr;
}

// Accepts only digits (optionally a leading '+'), value in [1, INT_MAX].
bool PmergeMe::parseNumber(const std::string &token, int &out)
{
	size_t i = 0;
	long value = 0;

	if (token.empty())
		return false;
	if (token[0] == '+')
		i = 1;
	if (i == token.size())
		return false;
	for (; i < token.size(); ++i)
	{
		if (token[i] < '0' || token[i] > '9')
			return false;
		value = value * 10 + (token[i] - '0');
		if (value > INT_MAX)
			return false;
	}
	if (value == 0) // "positive" integer: 0 is rejected
		return false;
	out = static_cast<int>(value);
	return true;
}

// Each argv can contain one or several numbers ("3 5 9" works too).
bool PmergeMe::validateArgs(int argc, char **argv, std::vector<int> &out)
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		bool any = false;
		while (iss >> token)
		{
			int n;
			if (!parseNumber(token, n))
				return false;
			out.push_back(n);
			any = true;
		}
		if (!any) // empty argument like ""
			return false;
	}
	return !out.empty();
}

/* ************************************************************************** */
/*                             std::vector version                            */
/* ************************************************************************** */

void PmergeMe::fillVector(int argc, char **argv, std::vector<int> &data)
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		int n;
		while (iss >> token)
			if (parseNumber(token, n))
				data.push_back(n);
	}
}

// Binary search in chain[0 .. end) for the first element greater than value.
// Searching in a range of size 2^k - 1 costs exactly k comparisons.
size_t PmergeMe::binaryInsertPosVector(const std::vector<int> &vals,
                                       const std::vector<size_t> &chain,
                                       size_t end, int value)
{
	size_t lo = 0;
	size_t hi = end;
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (lessThan(value, vals[chain[mid]]))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

/*
** elems = indexes into vals that must be sorted (by their value).
** Returns those same indexes, in sorted order.
*/
std::vector<size_t> PmergeMe::mergeInsertVector(const std::vector<int> &vals,
                                                const std::vector<size_t> &elems)
{
	if (elems.size() <= 1)
		return elems;

	// ---- Step 1: make pairs, put the bigger one ("winner") first ----------
	std::vector<size_t> winners;
	std::vector<size_t> loserOf(vals.size()); // loserOf[winner] = its loser
	winners.reserve(elems.size() / 2);
	for (size_t i = 0; i + 1 < elems.size(); i += 2)
	{
		size_t a = elems[i];
		size_t b = elems[i + 1];
		if (lessThan(vals[a], vals[b]))
			std::swap(a, b);
		winners.push_back(a);
		loserOf[a] = b;
	}
	bool hasStraggler = (elems.size() % 2 == 1);
	size_t straggler = hasStraggler ? elems[elems.size() - 1] : 0;

	// ---- Step 2: recursively sort the winners -----------------------------
	// sortedWinners = a1 a2 a3 ... am  (a1 < a2 < ... < am)
	std::vector<size_t> sortedWinners = mergeInsertVector(vals, winners);

	// pend = b1 b2 b3 ... bm (+ straggler), where bi is the loser of ai
	std::vector<size_t> pend;
	pend.reserve(sortedWinners.size() + 1);
	for (size_t i = 0; i < sortedWinners.size(); ++i)
		pend.push_back(loserOf[sortedWinners[i]]);
	if (hasStraggler)
		pend.push_back(straggler);

	// ---- Step 3: main chain = b1 a1 a2 ... am  (b1 < a1, free insert) -----
	std::vector<size_t> chain;
	chain.reserve(elems.size());
	chain.push_back(pend[0]);
	chain.insert(chain.end(), sortedWinners.begin(), sortedWinners.end());

	// ---- Step 4: insert b2..bm (+ straggler) in Jacobsthal order ----------
	// Order: b3 b2, b5 b4, b11 b10 ... b6, b21 ... b12, ...
	// bi only needs to be searched in the part of the chain BEFORE ai.
	size_t m = pend.size();   // bi is pend[i - 1] (1-based numbering)
	size_t prevJ = 1;         // b1 is already inserted
	size_t k = 3;             // jacobsthal(3) == 3
	while (prevJ < m)
	{
		size_t top = std::min(jacobsthal(k), m);
		for (size_t i = top; i > prevJ; --i)
		{
			size_t elem = pend[i - 1];
			size_t end;
			if (i - 1 < sortedWinners.size())
			{
				// position of ai in the chain = upper bound of the search
				end = std::find(chain.begin(), chain.end(), sortedWinners[i - 1])
				      - chain.begin();
			}
			else
				end = chain.size(); // straggler has no partner: whole chain
			size_t pos = binaryInsertPosVector(vals, chain, end, vals[elem]);
			chain.insert(chain.begin() + pos, elem);
		}
		prevJ = top;
		++k;
	}
	return chain;
}

void PmergeMe::sortVector(std::vector<int> &data)
{
	std::vector<size_t> idx(data.size());
	for (size_t i = 0; i < data.size(); ++i)
		idx[i] = i;

	std::vector<size_t> order = mergeInsertVector(data, idx);

	std::vector<int> result;
	result.reserve(data.size());
	for (size_t i = 0; i < order.size(); ++i)
		result.push_back(data[order[i]]);
	data.swap(result);
}

/* ************************************************************************** */
/*                             std::deque version                             */
/* ************************************************************************** */

void PmergeMe::fillDeque(int argc, char **argv, std::deque<int> &data)
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		int n;
		while (iss >> token)
			if (parseNumber(token, n))
				data.push_back(n);
	}
}

size_t PmergeMe::binaryInsertPosDeque(const std::deque<int> &vals,
                                      const std::deque<size_t> &chain,
                                      size_t end, int value)
{
	size_t lo = 0;
	size_t hi = end;
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (lessThan(value, vals[chain[mid]]))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

std::deque<size_t> PmergeMe::mergeInsertDeque(const std::deque<int> &vals,
                                              const std::deque<size_t> &elems)
{
	if (elems.size() <= 1)
		return elems;

	// Step 1: pairs
	std::deque<size_t> winners;
	std::deque<size_t> loserOf(vals.size());
	for (size_t i = 0; i + 1 < elems.size(); i += 2)
	{
		size_t a = elems[i];
		size_t b = elems[i + 1];
		if (lessThan(vals[a], vals[b]))
			std::swap(a, b);
		winners.push_back(a);
		loserOf[a] = b;
	}
	bool hasStraggler = (elems.size() % 2 == 1);
	size_t straggler = hasStraggler ? elems[elems.size() - 1] : 0;

	// Step 2: recursion on winners
	std::deque<size_t> sortedWinners = mergeInsertDeque(vals, winners);

	std::deque<size_t> pend;
	for (size_t i = 0; i < sortedWinners.size(); ++i)
		pend.push_back(loserOf[sortedWinners[i]]);
	if (hasStraggler)
		pend.push_back(straggler);

	// Step 3: main chain
	std::deque<size_t> chain(sortedWinners);
	chain.push_front(pend[0]);

	// Step 4: Jacobsthal insertion
	size_t m = pend.size();
	size_t prevJ = 1;
	size_t k = 3;
	while (prevJ < m)
	{
		size_t top = std::min(jacobsthal(k), m);
		for (size_t i = top; i > prevJ; --i)
		{
			size_t elem = pend[i - 1];
			size_t end;
			if (i - 1 < sortedWinners.size())
				end = std::find(chain.begin(), chain.end(), sortedWinners[i - 1])
				      - chain.begin();
			else
				end = chain.size();
			size_t pos = binaryInsertPosDeque(vals, chain, end, vals[elem]);
			chain.insert(chain.begin() + pos, elem);
		}
		prevJ = top;
		++k;
	}
	return chain;
}

void PmergeMe::sortDeque(std::deque<int> &data)
{
	std::deque<size_t> idx;
	for (size_t i = 0; i < data.size(); ++i)
		idx.push_back(i);

	std::deque<size_t> order = mergeInsertDeque(data, idx);

	std::deque<int> result;
	for (size_t i = 0; i < order.size(); ++i)
		result.push_back(data[order[i]]);
	data.swap(result);
}

/* ************************************************************************** */
/*                                    Run                                     */
/* ************************************************************************** */

template <typename C>
static void printSequence(const std::string &label, const C &c)
{
	std::cout << label;
	for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

int PmergeMe::run(int argc, char **argv)
{
	std::vector<int> input;
	if (argc < 2 || !validateArgs(argc, argv, input))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	// vector: timing includes data management (parsing + filling) and sorting
	std::clock_t start = std::clock();
	std::vector<int> vec;
	fillVector(argc, argv, vec);
	sortVector(vec);
	std::clock_t end = std::clock();
	double vecTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	// deque
	start = std::clock();
	std::deque<int> deq;
	fillDeque(argc, argv, deq);
	sortDeque(deq);
	end = std::clock();
	double deqTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	printSequence("Before:", input);
	printSequence("After: ", vec);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size()
	          << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
	          << " elements with std::deque  : " << deqTime << " us" << std::endl;
	return 0;
}

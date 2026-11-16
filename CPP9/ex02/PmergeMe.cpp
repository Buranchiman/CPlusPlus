#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <ctime>

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

bool PmergeMe::lessThan(int a, int b)
{
	++_comparisons;
	return a < b;
}

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
	if (value == 0)
		return false;
	out = static_cast<int>(value);
	return true;
}

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
		if (!any)
			return false;
	}
	return !out.empty();
}

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

void PmergeMe::blockSortVector(std::vector<int> &v, size_t bs)
{
	size_t nbBlocks = v.size() / bs;
	if (nbBlocks < 2)
		return;

	for (size_t i = 0; i + 1 < nbBlocks; i += 2)
	{
		size_t left = i * bs;
		size_t right = (i + 1) * bs;
		if (lessThan(v[right + bs - 1], v[left + bs - 1]))
			std::swap_ranges(v.begin() + left, v.begin() + left + bs,
			                 v.begin() + right);
	}

	blockSortVector(v, bs * 2);

	size_t nbPairs = nbBlocks / 2;
	std::vector<size_t> mainChain;
	std::vector<size_t> pend;
	std::vector<size_t> partner; 

	mainChain.push_back(0);
	mainChain.push_back(bs);
	for (size_t p = 1; p < nbPairs; ++p)
	{
		mainChain.push_back((2 * p + 1) * bs);
		pend.push_back(2 * p * bs);
		partner.push_back((2 * p + 1) * bs);
	}
	if (nbBlocks % 2 == 1)
		pend.push_back((nbBlocks - 1) * bs);

	size_t m = pend.size() + 1;
	size_t prevJ = 1;
	size_t k = 3;
	while (prevJ < m)
	{
		size_t top = std::min(jacobsthal(k), m);
		for (size_t i = top; i > prevJ; --i)
		{
			size_t blockStart = pend[i - 2];
			int value = v[blockStart + bs - 1];

			size_t end;
			if (i - 2 < partner.size())
				end = std::find(mainChain.begin(), mainChain.end(), partner[i - 2])
				      - mainChain.begin();
			else
				end = mainChain.size();

			size_t lo = 0;
			size_t hi = end;
			while (lo < hi)
			{
				size_t mid = lo + (hi - lo) / 2;
				if (lessThan(value, v[mainChain[mid] + bs - 1]))
					hi = mid;
				else
					lo = mid + 1;
			}
			mainChain.insert(mainChain.begin() + lo, blockStart);
		}
		prevJ = top;
		++k;
	}

	std::vector<int> result;
	result.reserve(v.size());
	for (size_t i = 0; i < mainChain.size(); ++i)
		result.insert(result.end(), v.begin() + mainChain[i],
		              v.begin() + mainChain[i] + bs);
	result.insert(result.end(), v.begin() + nbBlocks * bs, v.end());
	v.swap(result);
}

void PmergeMe::sortVector(std::vector<int> &data)
{
	blockSortVector(data, 1);
}

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

void PmergeMe::blockSortDeque(std::deque<int> &d, size_t bs)
{
	size_t nbBlocks = d.size() / bs;
	if (nbBlocks < 2)
		return;

	for (size_t i = 0; i + 1 < nbBlocks; i += 2)
	{
		size_t left = i * bs;
		size_t right = (i + 1) * bs;
		if (lessThan(d[right + bs - 1], d[left + bs - 1]))
			std::swap_ranges(d.begin() + left, d.begin() + left + bs,
			                 d.begin() + right);
	}

	blockSortDeque(d, bs * 2);

	size_t nbPairs = nbBlocks / 2;
	std::deque<size_t> mainChain;
	std::deque<size_t> pend;
	std::deque<size_t> partner;

	mainChain.push_back(0);
	mainChain.push_back(bs);
	for (size_t p = 1; p < nbPairs; ++p)
	{
		mainChain.push_back((2 * p + 1) * bs);
		pend.push_back(2 * p * bs);
		partner.push_back((2 * p + 1) * bs);
	}
	if (nbBlocks % 2 == 1)
		pend.push_back((nbBlocks - 1) * bs);

	size_t m = pend.size() + 1;
	size_t prevJ = 1;
	size_t k = 3;
	while (prevJ < m)
	{
		size_t top = std::min(jacobsthal(k), m);
		for (size_t i = top; i > prevJ; --i)
		{
			size_t blockStart = pend[i - 2];
			int value = d[blockStart + bs - 1];

			size_t end;
			if (i - 2 < partner.size())
				end = std::find(mainChain.begin(), mainChain.end(), partner[i - 2])
				      - mainChain.begin();
			else
				end = mainChain.size();

			size_t lo = 0;
			size_t hi = end;
			while (lo < hi)
			{
				size_t mid = lo + (hi - lo) / 2;
				if (lessThan(value, d[mainChain[mid] + bs - 1]))
					hi = mid;
				else
					lo = mid + 1;
			}
			mainChain.insert(mainChain.begin() + lo, blockStart);
		}
		prevJ = top;
		++k;
	}

	std::deque<int> result;
	for (size_t i = 0; i < mainChain.size(); ++i)
		result.insert(result.end(), d.begin() + mainChain[i],
		              d.begin() + mainChain[i] + bs);
	result.insert(result.end(), d.begin() + nbBlocks * bs, d.end());
	d.swap(result);
}

void PmergeMe::sortDeque(std::deque<int> &data)
{
	blockSortDeque(data, 1);
}

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

	std::clock_t start = std::clock();
	std::vector<int> vec;
	fillVector(argc, argv, vec);
	sortVector(vec);
	std::clock_t end = std::clock();
	double vecTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

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
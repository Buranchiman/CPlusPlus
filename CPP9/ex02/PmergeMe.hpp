#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstddef>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int run(int argc, char **argv);

	unsigned long getComparisons() const;

private:
	unsigned long _comparisons;

	static bool parseNumber(const std::string &token, int &out);
	static bool validateArgs(int argc, char **argv, std::vector<int> &out);

	bool lessThan(int a, int b);
	static size_t jacobsthal(size_t k);

	void fillVector(int argc, char **argv, std::vector<int> &data);
	void sortVector(std::vector<int> &data);
	void blockSortVector(std::vector<int> &v, size_t blockSize);

	void fillDeque(int argc, char **argv, std::deque<int> &data);
	void sortDeque(std::deque<int> &data);
	void blockSortDeque(std::deque<int> &d, size_t blockSize);
};

#endif
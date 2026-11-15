#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstddef>

/*
** Ford-Johnson (merge-insertion) sort, implemented twice:
**   - once with std::vector
**   - once with std::deque
**
** Both versions sort INDEXES into the value container instead of the values
** themselves. That way every element is unique (even with duplicate values),
** so after the recursive call we always know which loser belongs to which
** winner.
*/
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	// Returns 0 on success, 1 on error (an error message is already printed)
	int run(int argc, char **argv);

	unsigned long getComparisons() const;

private:
	unsigned long _comparisons; // number of value comparisons (for testing)

	// parsing
	static bool parseNumber(const std::string &token, int &out);
	static bool validateArgs(int argc, char **argv, std::vector<int> &out);

	bool lessThan(int a, int b);
	static size_t jacobsthal(size_t k);

	// ---------- std::vector version ----------
	void fillVector(int argc, char **argv, std::vector<int> &data);
	void sortVector(std::vector<int> &data);
	std::vector<size_t> mergeInsertVector(const std::vector<int> &vals,
	                                      const std::vector<size_t> &elems);
	size_t binaryInsertPosVector(const std::vector<int> &vals,
	                             const std::vector<size_t> &chain,
	                             size_t end, int value);

	// ---------- std::deque version ----------
	void fillDeque(int argc, char **argv, std::deque<int> &data);
	void sortDeque(std::deque<int> &data);
	std::deque<size_t> mergeInsertDeque(const std::deque<int> &vals,
	                                    const std::deque<size_t> &elems);
	size_t binaryInsertPosDeque(const std::deque<int> &vals,
	                            const std::deque<size_t> &chain,
	                            size_t end, int value);
};

#endif

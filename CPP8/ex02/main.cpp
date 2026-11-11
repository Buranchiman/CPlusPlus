#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void	print(int x)
{
	std::cout << x << ", ";
}

int main()
{
	// ===================== SUBJECT WITH MUTANTSTACK =====================
	std::cout << BOLDGREEN << "Beginning subject tests with MutantStack-----------------" << RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << GREEN << mstack.top() << RESET << std::endl;
		mstack.pop();
		std::cout << GREEN << mstack.size() << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << GREEN << *it << RESET << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "Copied into a std::stack, its top is: " << s.top() << " (expected 0)" << std::endl;
	}
	std::cout << BOLDGREEN << "Ending subject tests with MutantStack-----------------" << RESET << std::endl << std::endl;

	// ===================== SAME TEST WITH STD::LIST =====================
	std::cout << BOLDMAGENTA << "Beginning subject tests with std::list (output must match)-----------------" << RESET << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << GREEN << lst.back() << RESET << std::endl;
		lst.pop_back();
		std::cout << GREEN << lst.size() << RESET << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << GREEN << *it << RESET << std::endl;
			++it;
		}
		std::list<int> s(lst);
		std::cout << "Copied into a std::list, its back is: " << s.back() << " (expected 0)" << std::endl;
	}
	std::cout << BOLDMAGENTA << "Ending subject tests with std::list-----------------" << RESET << std::endl << std::endl;

	// ===================== STACK BEHAVIOUR =====================
	std::cout << BOLDRED << "Beginning stack behaviour tests-----------------" << RESET << std::endl;
	std::cout << "Empty stack :" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "empty: " << (mstack.empty() ? "true" : "false") << " (expected true)" << std::endl;
		std::cout << "size: " << mstack.size() << " (expected 0)" << std::endl;
		if (mstack.begin() == mstack.end())
			std::cout << GREEN << "begin() == end() on an empty stack" << RESET << std::endl;
		else
			std::cerr << RED << "begin() != end() on an empty stack" << RESET << std::endl;
	}

	std::cout << "Push, pop and iterate after each change :" << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 1; i <= 5; i++)
			mstack.push(i * 10);
		std::cout << "Content (bottom to top): ";
		std::for_each(mstack.begin(), mstack.end(), print);
		std::cout << std::endl;
		mstack.pop();
		mstack.pop();
		std::cout << "After 2 pops: ";
		std::for_each(mstack.begin(), mstack.end(), print);
		std::cout << std::endl;
		std::cout << GREEN << "top: " << mstack.top() << " (expected 30), size: " << mstack.size() << " (expected 3)" << RESET << std::endl;
	}
	std::cout << BOLDRED << "Ending stack behaviour tests-----------------" << RESET << std::endl << std::endl;

	// ===================== ITERATORS =====================
	std::cout << BOLDBLUE << "Beginning iterator tests-----------------" << RESET << std::endl;
	std::cout << "Modifying values through an iterator :" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			*it *= 100;
		std::cout << "Content: ";
		std::for_each(mstack.begin(), mstack.end(), print);
		std::cout << std::endl;
		std::cout << GREEN << "top: " << mstack.top() << " (expected 300)" << RESET << std::endl;
	}

	std::cout << "Reverse iterators (top to bottom, like popping) :" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		std::cout << "Content: ";
		for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
			std::cout << *rit << ", ";
		std::cout << "(expected 4, 3, 2, 1)" << std::endl;
	}

	std::cout << "const_iterator on a const MutantStack :" << std::endl;
	{
		MutantStack<int> tmp;
		tmp.push(7);
		tmp.push(8);
		tmp.push(9);
		const MutantStack<int> cstack(tmp);
		std::cout << "Content: ";
		for (MutantStack<int>::const_iterator cit = cstack.begin(); cit != cstack.end(); ++cit)
			std::cout << *cit << ", ";
		std::cout << std::endl;
		// *cstack.begin() = 1;   // would NOT compile: const_iterator is read only
	}

	std::cout << "STL algorithms on a MutantStack :" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(42);
		mstack.push(-8);
		mstack.push(15);
		mstack.push(99);
		MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 15);
		if (found != mstack.end())
			std::cout << GREEN << "std::find found: " << *found << RESET << std::endl;
		std::cout << GREEN << "std::max_element: " << *std::max_element(mstack.begin(), mstack.end()) << " (expected 99)" << RESET << std::endl;
		std::cout << GREEN << "std::count of 42: " << std::count(mstack.begin(), mstack.end(), 42) << " (expected 1)" << RESET << std::endl;
		if (std::find(mstack.begin(), mstack.end(), 1000) == mstack.end())
			std::cerr << RED << "std::find did not find 1000" << RESET << std::endl;
	}
	std::cout << BOLDBLUE << "Ending iterator tests-----------------" << RESET << std::endl << std::endl;

	// ===================== COPY =====================
	std::cout << BOLDCYAN << "Beginning copy tests-----------------" << RESET << std::endl;
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);
		MutantStack<int> b(a);
		MutantStack<int> c;
		c = a;
		b.push(3);      // b and c are independent from a
		c.pop();
		std::cout << "a: ";
		std::for_each(a.begin(), a.end(), print);
		std::cout << "(expected 1, 2)" << std::endl;
		std::cout << "b: ";
		std::for_each(b.begin(), b.end(), print);
		std::cout << "(expected 1, 2, 3)" << std::endl;
		std::cout << "c: ";
		std::for_each(c.begin(), c.end(), print);
		std::cout << "(expected 1)" << std::endl;
	}
	std::cout << BOLDCYAN << "Ending copy tests-----------------" << RESET << std::endl << std::endl;

	// ===================== OTHER TYPES / CONTAINERS =====================
	std::cout << BOLDYELLOW << "Beginning other types and containers tests-----------------" << RESET << std::endl;
	std::cout << "MutantStack<std::string> :" << std::endl;
	{
		MutantStack<std::string> sstack;
		sstack.push("Hello");
		sstack.push("mutant");
		sstack.push("world");
		std::cout << "Content: ";
		for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << GREEN << "first word via it->size(): " << sstack.begin()->size() << " (expected 5, Hello)" << RESET << std::endl;
	}

	std::cout << "MutantStack built on a std::vector :" << std::endl;
	{
		MutantStack<int, std::vector<int> > vstack;
		vstack.push(4);
		vstack.push(5);
		vstack.push(6);
		std::cout << "Content: ";
		std::for_each(vstack.begin(), vstack.end(), print);
		std::cout << std::endl;
		std::cout << GREEN << "begin()[1]: " << vstack.begin()[1] << " (expected 5, random access works)" << RESET << std::endl;
	}

	std::cout << "MutantStack built on a std::list :" << std::endl;
	{
		MutantStack<int, std::list<int> > lstack;
		lstack.push(7);
		lstack.push(8);
		lstack.push(9);
		std::cout << "Content: ";
		std::for_each(lstack.begin(), lstack.end(), print);
		std::cout << std::endl;
	}

	std::cout << "100,000 elements :" << std::endl;
	{
		MutantStack<int> big;
		long sum = 0;
		for (int i = 0; i < 100000; i++)
			big.push(i);
		for (MutantStack<int>::iterator it = big.begin(); it != big.end(); ++it)
			sum += *it;
		std::cout << GREEN << "size: " << big.size() << ", sum: " << sum << " (expected 4999950000)" << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "Ending other types and containers tests-----------------" << RESET << std::endl;
	return 0;
}

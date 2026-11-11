#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <climits>

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

int main()
{
	// ===================== SUBJECT =====================
	std::cout << BOLDGREEN << "Beginning subject tests-----------------" << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << GREEN << sp.shortestSpan() << RESET << std::endl;   // 2
		std::cout << GREEN << sp.longestSpan() << RESET << std::endl;    // 14
	}
	std::cout << BOLDGREEN << "Ending subject tests-----------------" << RESET << std::endl << std::endl;

	// ===================== ERRORS =====================
	std::cout << BOLDRED << "Beginning error tests-----------------" << RESET << std::endl;
	std::cout << "Adding to an already full span test :" << std::endl;
	{
		Span sp(2);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << "Trying span functions on empty or one member spans :" << std::endl;
	{
		Span sp(10);
		try { sp.shortestSpan(); }
		catch (const std::exception& e) { std::cerr << RED << "Empty: " << e.what() << RESET << std::endl; }
		sp.addNumber(42);
		try { sp.longestSpan(); }
		catch (const std::exception& e) { std::cerr << RED << "One number: " << e.what() << RESET << std::endl; }
	}

	std::cout << "Span of size 0 :" << std::endl;
	{
		Span sp(0);
		try { sp.addNumber(1); }
		catch (const std::exception& e) { std::cerr << RED << "Exception: " << e.what() << RESET << std::endl; }
	}
	std::cout << BOLDRED << "Ending error tests-----------------" << RESET << std::endl << std::endl;

	// ===================== ADDITIONAL =====================
	std::cout << BOLDBLUE << "Beginning additional tests-----------------" << RESET << std::endl;
	std::cout << "Biggest ranges test :" << std::endl;
	{
		Span sp(4);
		sp.addNumber(-5);
		sp.addNumber(-1);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		std::cout << GREEN << "shortest: " << sp.shortestSpan() << " (expected 4)" << RESET << std::endl;
		std::cout << GREEN << "longest:  " << sp.longestSpan()  << " (expected 4294967295)" << RESET << std::endl;
	}

	std::cout << "Duplicate tests :" << std::endl;
	{
		Span sp(3);
		sp.addNumber(7);
		sp.addNumber(100);
		sp.addNumber(7);
		std::cout << GREEN << "shortest: " << sp.shortestSpan() << " (expected 0)" << RESET << std::endl;
	}

	std::cout << "Copy constructor and assignment tests :" << std::endl;
	{
		Span a(3);
		a.addNumber(1);
		a.addNumber(10);
		Span b(a);
		Span c(1);
		c = a;
		b.addNumber(100);   // b is independent from a
		std::cout << GREEN << "a longest: " << a.longestSpan() << " (expected 9)" << RESET << std::endl;
		std::cout << GREEN << "b longest: " << b.longestSpan() << " (expected 99)" << RESET << std::endl;
		std::cout << GREEN << "c longest: " << c.longestSpan() << " (expected 9)" << RESET << std::endl;
	}
	std::cout << BOLDBLUE << "Ending additional tests-----------------" << RESET << std::endl << std::endl;

	// ===================== BIG TESTS =====================
	std::cout << BOLDYELLOW << "Beginning improved addnumber tests-----------------" << RESET << std::endl;
	std::cout << "100,000 random numbers with addRange :" << std::endl;
	{
		const unsigned int n = 100000;
		std::srand(std::time(NULL));
		std::vector<int> v;
		for (unsigned int i = 0; i < n; i++)
			v.push_back(std::rand());
		Span sp(n);
		sp.addRange(v.begin(), v.end());
		std::cout << GREEN << "size:     " << sp.size() << RESET << std::endl;
		std::cout << GREEN << "shortest: " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "longest:  " << sp.longestSpan() << RESET << std::endl;
	}

	std::cout << "10,000 known numbers with addNumber :" << std::endl;
	{
		Span sp(10000);
		for (int i = 0; i < 10000; i++)
			sp.addNumber(i * 3);
		std::cout << GREEN << "shortest: " << sp.shortestSpan() << " (expected 3)" << RESET << std::endl;
		std::cout << GREEN << "longest:  " << sp.longestSpan()  << " (expected 29997)" << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "Ending improved addnumber tests-----------------" << RESET << std::endl;
	return 0;
}

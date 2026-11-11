#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <algorithm>
#include <iostream>
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

void    print(int x)
{
    std::cout << x << ", ";
}

int main(void)
{
    // ===================== VECTOR =====================
    std::cout << BOLDMAGENTA << "Beginning vector tests-----------------" << RESET << std::endl;
    std::vector<int> v;
    std::vector<int>::const_iterator vit;
    std::vector<int>::const_iterator vite;
    std::vector<int>::const_iterator vtmp;

    std::cout << "Trying in empty container:" << std::endl;
    try
    {
        easyfind(v, 7);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    v.push_back(3);
    v.push_back(7);
    v.push_back(-2);
    v.push_back(9);
    vit = v.begin();
    vite = v.end();
    std::cout << "Content of vector is: ";
    std::for_each(vit, vite, print);
    std::cout << std::endl;
    vtmp = easyfind(v, 3);
    std::cout << GREEN << "Return of easyfind for 3 is: " << *vtmp << RESET << std::endl;
    vtmp = easyfind(v, -2);
    std::cout << GREEN << "Return of easyfind for -2 is: " << *vtmp
              << " (index " << std::distance(vit, vtmp) << ")" << RESET << std::endl;
    std::cout << "Trying to find 5 in vector: " << std::endl;
    try
    {
        easyfind(v, 5);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    std::cout << BOLDMAGENTA << "Ending vector tests-----------------" << RESET << std::endl << std::endl;

    // ===================== LIST =====================
    std::cout << BOLDCYAN << "Beginning list tests-----------------" << RESET << std::endl;
    std::list<int> l;
    std::list<int>::const_iterator lit;
    std::list<int>::const_iterator lite;
    std::list<int>::const_iterator ltmp;

    std::cout << "Trying in empty container:" << std::endl;
    try
    {
        easyfind(l, 42);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    l.push_back(10);
    l.push_back(42);
    l.push_back(-7);
    l.push_back(42);    // duplicate: easyfind must return the FIRST one
    l.push_front(0);    // list can also insert at the front
    lit = l.begin();
    lite = l.end();
    std::cout << "Content of list is: ";
    std::for_each(lit, lite, print);
    std::cout << std::endl;
    ltmp = easyfind(l, 42);
    std::cout << GREEN << "Return of easyfind for 42 is: " << *ltmp
              << " (position " << std::distance(lit, ltmp) << ", first occurrence)" << RESET << std::endl;
    ltmp = easyfind(l, 0);
    std::cout << GREEN << "Return of easyfind for 0 (front) is: " << *ltmp << RESET << std::endl;
    ltmp = easyfind(l, 42);
    ++ltmp;
    std::cout << GREEN << "Element right after the first 42 is: " << *ltmp << RESET << std::endl;
    std::cout << "Trying to find 100 in list: " << std::endl;
    try
    {
        easyfind(l, 100);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    std::cout << BOLDCYAN << "Ending list tests-----------------" << RESET << std::endl << std::endl;

    // ===================== DEQUE =====================
    std::cout << BOLDYELLOW << "Beginning deque tests-----------------" << RESET << std::endl;
    std::deque<int> d;
    std::deque<int>::const_iterator dit;
    std::deque<int>::const_iterator dite;
    std::deque<int>::const_iterator dtmp;

    std::cout << "Trying in empty container:" << std::endl;
    try
    {
        easyfind(d, 1);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    d.push_back(5);
    d.push_back(15);
    d.push_front(-1);
    d.push_front(INT_MAX);
    d.push_back(INT_MIN);
    dit = d.begin();
    dite = d.end();
    std::cout << "Content of deque is: ";
    std::for_each(dit, dite, print);
    std::cout << std::endl;
    dtmp = easyfind(d, INT_MAX);
    std::cout << GREEN << "Return of easyfind for INT_MAX (front) is: " << *dtmp << RESET << std::endl;
    dtmp = easyfind(d, INT_MIN);
    std::cout << GREEN << "Return of easyfind for INT_MIN (back) is: " << *dtmp << RESET << std::endl;
    std::cout << "Trying to find 6 in deque: " << std::endl;
    try
    {
        easyfind(d, 6);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    std::cout << BOLDYELLOW << "Ending deque tests-----------------" << RESET << std::endl << std::endl;

    // ===================== BIG VECTOR =====================
    std::cout << BOLDBLUE << "Beginning big vector tests-----------------" << RESET << std::endl;
    std::vector<int> big;
    std::vector<int>::const_iterator btmp;

    for (int i = 0; i < 100000; i++)
        big.push_back(i * 2);   // only even numbers
    std::cout << "Vector of " << big.size() << " even numbers (0 to " << big.back() << ")" << std::endl;
    btmp = easyfind(big, 199998);
    std::cout << GREEN << "Return of easyfind for 199998 (last) is: " << *btmp << RESET << std::endl;
    std::cout << "Trying to find 777 (odd) in big vector: " << std::endl;
    try
    {
        easyfind(big, 777);
    }
    catch(const NoMatchFound &e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    std::cout << BOLDBLUE << "Ending big vector tests-----------------" << RESET << std::endl;

    return (0);
}

#include "easyfind.hpp"
#include <vector>

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

int	main(void)
{
	std::cout << BOLDMAGENTA << "Beginning vector tests-----------------" << std::endl;
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
		std::cerr << e.what() << '\n';
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
	std::cout << "Return of easyfind for 3 is: " << *vtmp << std::endl;
	std::cout << "Trying to find 5 in vector: " << std::endl;
	try
	{
		easyfind(v, 5);
	}
	catch(const NoMatchFound &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Beginning vector tests-----------------" <<  WHITE << std::endl;
}

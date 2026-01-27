#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat joe;

	std::cout << joe;
	try
	{
		Bureaucrat unreal("allmighty", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	joe.promote();
	std::cout <<joe;
	joe.demote();
	std::cout <<joe;
	Bureaucrat low("low", 150);
	Bureaucrat high("high", 1);
	try
	{
		high.promote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		low.demote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

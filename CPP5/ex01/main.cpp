#include "Bureaucrat.hpp"
#include "colors.hpp"

int	main(void)
{
	Bureaucrat joe;

	std:: cout << BOLDRED << "Running previous tests to ensure bureaucrat is still working -----------------------------" << std::endl;
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
	std:: cout << "End of bureaucrat test -----------------------------" << WHITE << std::endl;
	std:: cout << BOLDBLUE << "Running Form tests -----------------------------" << std::endl;

}

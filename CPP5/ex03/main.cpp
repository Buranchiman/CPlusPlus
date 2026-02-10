#include "Bureaucrat.hpp"
#include "colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	std:: cout << BOLDBLUE << "Running AForm tests -----------------------------" << std::endl;
	try
	{
		ShrubberyCreationForm	toohigh;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm	toolow;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	ShrubberyCreationForm	basic("bush");
	std::cout << basic;
	try
	{
		low.signAForm(basic);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << basic;
	high.signAForm(basic);
	std::cout << basic;
	low.executeForm(basic);
	high.executeForm(basic);
	RobotomyRequestForm robot("Bobby");
	low.executeForm(robot);
	high.executeForm(robot);
	high.signAForm(robot);
	high.executeForm(robot);
	PresidentialPardonForm pres("Bobby");
	high.signAForm(pres);
	high.executeForm(pres);
	std:: cout << "End of AForm tests -----------------------------" << WHITE << std::endl;
	std:: cout << BOLDGREEN << "Starting Intern tests -----------------------------" << std::endl;
	Intern	intern;
	AForm*	test = intern.makeForm("shrubbery creation", "bigger_bush");
	try
	{
		low.signAForm(*test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	low.executeForm(*test);
	high.signAForm(*test);
	high.executeForm(*test);
}

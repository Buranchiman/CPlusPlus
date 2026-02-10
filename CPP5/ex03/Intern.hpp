#ifndef Intern_HPP
#define Intern_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

struct Tab
{
		const char	*key;
		AForm*		(*create)(std::string target);
};

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(std::string name, std::string target);
};

#endif

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
	}
	return *this;
}

Intern::~Intern() {
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*	correct;
	static	Tab	forms[3] =
	{
		{"shrubbery creation", &ShrubberyCreationForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"presidential pardon", &PresidentialPardonForm::create},
	};
	correct = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i].key)
		{
			correct = forms[i].create(target);
		}
	}
	return (correct);
}

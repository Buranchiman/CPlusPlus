#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45, "home") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	std::cout << "Trying to robotomize " << AForm::getTarget() <<" *Drilling noises* ..." << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << " Robotomy was a success !" << std::endl << "         __\n"
		" _(\\    |@@|\n"
		"(__/\\__ \\--/ __\n"
		"   \\___|----|  |   __\n"
		"       \\ }{ /\\ )_ / _\\\n"
		"       /\\__/\\ \\__O (__\n"
		"      (--/\\--)    \\__/\n"
		"      _)(  )(_\n"
		"     `---''---`\n";
	}
	else
	{
		std::cout << "Robotomy has failed :/" << std::endl;
	}
}

AForm* RobotomyRequestForm::create(std::string target)
{
	return (new RobotomyRequestForm(target));
}

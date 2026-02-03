#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137, "home") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream file(AForm::getTarget() + "_shrubbery");
	if (!file.is_open())
	{
		std::cerr << "Failed to open file\n";
		return ;
	}
	file << R"(
                     .o00o
                   o000000oo
                  00000000000o
                 00000000000000
              oooooo  00000000  o88o
           ooOOOOOOOoo  ```''  888888
         OOOOOOOOOOOO'.qQQQQq. `8888'
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'
        OOOOOOOOOO'.QQQQQQQQQQ/ /q
         OOOOOOOOO QQQQQQQQQQ/ /QQ
           OOOOOOOOO `QQQQQQ/ /QQ'
             OO:F_P:O `QQQ/  /Q'
                \\. \ |  // |
                d\ \\\|_////
                qP| \\ _' `|Ob
                   \  / \  \Op
                   |  | O| |
           _       /\. \_/ /\
            `---__/|_\\   //|  __
                  `-'  `-'`-'-')";
	file.close();
}

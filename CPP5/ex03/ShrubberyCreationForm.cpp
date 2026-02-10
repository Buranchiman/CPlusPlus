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
  (void)executor;
  std::string filename = AForm::getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Failed to open file\n";
		return ;
	}
  file <<
  "                     .o00o\n"
  "                   o000000oo\n"
  "                  00000000000o\n"
  "                 00000000000000\n"
  "              oooooo  00000000  o88o\n"
  "           ooOOOOOOOoo  ```''  888888\n"
  "         OOOOOOOOOOOO'.qQQQQq. `8888'\n"
  "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
  "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
  "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
  "           OOOOOOOOO `QQQQQQ/ /QQ'\n"
  "             OO:F_P:O `QQQ/  /Q'\n"
  "                \\\\. \\ |  // |\n"
  "                d\\ \\\\\\|_////\n"
  "                qP| \\\\ _' `|Ob\n"
  "                   \\  / \\  \\Op\n"
  "                   |  | O| |\n"
  "           _       /\\. \\_/ /\\\n"
  "            `---__/|_\\\\   //|  __\n"
  "                  `-'  `-'`-'-'\n";
	file.close();
}

AForm* ShrubberyCreationForm::create(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

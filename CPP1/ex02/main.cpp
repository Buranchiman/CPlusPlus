#include <iostream>

int main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "address of string is: " << &str << " | "
			  << "address held by stringPTR is: " << stringPTR << " | "
			  << "address held by stringREF is: " <<  &stringREF << '\n';
	std::cout << "value of string is: " << str << " | "
			  << "value point to by stringPTR is: " << *stringPTR << " | "
			  << "value pointed to by stringREF is: " <<  stringREF << '\n';
}

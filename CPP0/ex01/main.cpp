#include "PhoneBook.hpp"

int	main(void)
{
	std::string line;
	while (1)
	{
		std::cout << "Please enter a command :\n->ADD to add a contact\n->SEARCH to search for an existing contact\n->EXIT to exit the phonebook\n";
		std::getline(std::cin, line);
	}
}

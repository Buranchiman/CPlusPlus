#include "PhoneBook.hpp"

int	main(void)
{
	std::string		line;
	PhoneBook		book;

	std::cout << "Please enter a command :\n->ADD to add a contact\n->SEARCH to search for an existing contact\n->EXIT to exit the phonebook\n";
	while (1)
	{
		std::cout << '>';
		if (!std::getline(std::cin, line))
			return (0);
		if (line == "ADD")
			book.addContactInput();
		else if (line == "SEARCH")
			book.searchContact();
		else if (line == "EXIT")
			break;
	}
	return (0);
}

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0) {}

PhoneBook::PhoneBook(const PhoneBook& other) : size(other.size)
{
	for (int i = 0; i < size; i++) {
		contacts[i] = other.contacts[i];
	}
}


PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this != &other) {
		size = other.size;
		for (int i = 0; i < size; i++) {
			contacts[i] = other.contacts[i];
		}
	}
	return *this;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact(const Contact& other)
{
	if (size < 8)
	{
		contacts[size] = other;
		size++;
	}
	else
	{
		contacts[size % 8] = other;
		size++;
	}
}

void PhoneBook::addContactInput(void)
{
	Contact contact;

	contact.contactFromInput();
	if (contact.getFirstName() == "" || contact.getLastName() == "" || contact.getPhone() == ""  || contact.getDarkest() == "")
		return ;
	addContact(contact);
}

void PhoneBook::searchContact(void)
{
	std::string line;
	if (!size)
	{
		std::cout << "Phonebook is empty\n";
		return ;
	}
	for (int i = 0; i < size && i < 8; i++)
	{
		std::cout << i + 1 << "|";
		contacts[i].displaySearch();
	}
	std::cout << "Please enter an index\n";
	if (!std::getline(std::cin, line))
		return ;
	int n = std::atoi(line.c_str());
	if (n < 1 || n > size)
	{
		std::cout << "Wrong index !\n";
		return ;
	}
	Contact contact = contacts[n - 1];
	contact.displayContact();
}

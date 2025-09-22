#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0) {}

// Copy constructor
PhoneBook::PhoneBook(const PhoneBook& other) : size(other.size) {
	for (int i = 0; i < size; i++) {
		contacts[i] = other.contacts[i]; // calls Contact's copy assignment
	}
}

// Copy assignment operator
PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this != &other) {
		size = other.size;
		for (int i = 0; i < size; i++) {
			contacts[i] = other.contacts[i]; // calls Contact's copy assignment
		}
	}
	return *this;
}

// Destructor
PhoneBook::~PhoneBook() {
	// Nothing special to do: contacts[] are destroyed automatically
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

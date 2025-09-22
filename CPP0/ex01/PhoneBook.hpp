#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
private:
		Contact	contacts[8];
		int		size;
public:
	// Orthodox Canonical Form
	PhoneBook();								// Default constructor
	PhoneBook(const PhoneBook& other);			// Copy constructor
	PhoneBook& operator=(const PhoneBook& other);	// Copy assignment operator
	~PhoneBook();								// Destructor

	// Methods
	void addContact(const Contact& c);
	const Contact& getContact(int index) const;
	int getSize() const;
};

#endif

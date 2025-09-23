#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
		Contact	contacts[8];
		int		size;
public:
	PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook& operator=(const PhoneBook& other);
	~PhoneBook();

	// Methods
	void			addContact(const Contact& c);
	const Contact&	getContact(int index) const;
	int				getSize() const;
	void			addContactInput();
	void			searchContact();
};

#endif

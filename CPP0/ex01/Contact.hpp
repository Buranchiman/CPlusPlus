#ifndef CONTACT_HPP
# define CONTACT_HP

#include <string>

class Contact
{
private:
	std::string FirstName, LastName, Phone, Darkest;
public:
	Contact();
	Contact(const std::string& FirstName,
			const std::string& LastName,
			const std::string& Phone,
			const std::string& Darkest);
	Contact(const Contact &other);
	Contact& operator=(const Contact& other);
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getPhone() const;
	const std::string& getDarkest() const;
	~Contact();
};

#endif

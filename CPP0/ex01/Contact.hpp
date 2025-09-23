#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact
{
private:
	std::string FirstName, LastName, NickName, Phone, Darkest;
public:
	Contact();
	Contact(const std::string& FirstName,
			const std::string& LastName,
			const std::string& NickName,
			const std::string& Phone,
			const std::string& Darkest);
	Contact(const Contact &other);
	Contact& operator=(const Contact& other);
	~Contact();
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickName() const;
	const std::string& getPhone() const;
	const std::string& getDarkest() const;
	void setName(const std::string& n);
	void setLastName(const std::string& l);
	void setNickName(const std::string& nn);
	void setPhone(const std::string& p);
	void setDarkest(const std::string& d);
	void contactFromInput(void);
	void displaySearch(void);
	void displayContact(void);
	static std::string formatField(const std::string &s);
};

#endif

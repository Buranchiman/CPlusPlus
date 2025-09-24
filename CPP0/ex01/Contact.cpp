#include "Contact.hpp"

// Default constructor
Contact::Contact() : FirstName(""), LastName(""), NickName(""), Phone(""), Darkest("") {}

Contact::Contact(const std::string& a,
				const std::string& b,
				const std::string& c,
				const std::string& d,
				const std::string& e)
	: FirstName(a), LastName(b), NickName(c), Phone(d), Darkest(e) {}

Contact::Contact(const Contact& other)
	: FirstName(other.FirstName), LastName(other.LastName), NickName(other.NickName), Phone(other.Phone), Darkest(other.Darkest) {}

// Copy assignment operator
Contact& Contact::operator=(const Contact& other)
{
	if (this != &other) {
		FirstName = other.FirstName;
		LastName = other.LastName;
		NickName = other.NickName;
		Phone = other.Phone;
		Darkest = other.Darkest;
	}
	return *this;
}

Contact::~Contact() {}

const std::string& Contact::getFirstName() const { return FirstName; }
const std::string& Contact::getLastName() const { return LastName; }
const std::string& Contact::getNickName() const { return NickName; }
const std::string& Contact::getPhone() const { return Phone; }
const std::string& Contact::getDarkest() const { return Darkest; }

void Contact::setName(const std::string& n) { FirstName = n; }
void Contact::setLastName(const std::string& l) { LastName = l; }
void Contact::setNickName(const std::string& nn) { NickName = nn; }
void Contact::setPhone(const std::string& e) { Phone = e; }
void Contact::setDarkest(const std::string& d) { Darkest = d; }

void Contact::contactFromInput(void)
{
	std::string line;

	std::cout << "Please enter the contact's first name: ";
	if (!std::getline(std::cin, line)) return ;
	setName(line);
	std::cout << "Please enter the contact's last name: ";
	if (!std::getline(std::cin, line)) return ;
	setLastName(line);
	std::cout << "Please enter the contact's  nickname: ";
	if (!std::getline(std::cin, line)) return ;
	setNickName(line);
	std::cout << "Please enter the contact's phone number: ";
	if (!std::getline(std::cin, line)) return ;
	setPhone(line);
	std::cout << "Please enter the contact's darkest secret: ";
	if (!std::getline(std::cin, line)) return ;
	setDarkest(line);
}

std::string Contact::formatField(const std::string &s)
{
	if (s.size() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void Contact::displaySearch(void)
{
	std::cout << std::setw(10) << std::right << formatField(FirstName) << "|";
	std::cout << std::setw(10) << std::right << formatField(LastName)  << "|";
	std::cout << std::setw(10) << std::right << formatField(NickName)  << "|";
	std::cout << std::endl;
}

void Contact::displayContact(void)
{
	std:: cout << "First name: " << FirstName << '\n'
			   << "Last name: " << LastName << '\n'
			   << "Nickname: " << NickName << '\n'
			   << "Phone number: " << Phone << '\n'
			   << "Darkest secret: " << Darkest << '\n';
}

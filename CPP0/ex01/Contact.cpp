#include "Contact.hpp"

// Default constructor
Contact::Contact() : FirstName(""), LastName(""), Phone(""), Darkest("") {}

// Parameterized constructor
Contact::Contact(const std::string& a,
				const std::string& b,
				const std::string& c,
				const std::string& d)
	: FirstName(a), LastName(b), Phone(c), Darkest(d) {}

// Copy constructor
Contact::Contact(const Contact& other)
	: FirstName(other.FirstName), LastName(other.LastName), Phone(other.Phone), Darkest(other.Darkest) {}

// Copy assignment operator
Contact& Contact::operator=(const Contact& other)
{
	if (this != &other) {  // self-assignment check
		FirstName = other.FirstName;
		LastName = other.LastName;
		Phone = other.Phone;
		Darkest = other.Darkest;
	}
	return *this;
}

// Destructor
Contact::~Contact() {
	// nothing special needed since std::string cleans up automatically
}

// Getters
const std::string& Contact::getFirstName() const { return FirstName; }
const std::string& Contact::getLastName() const { return LastName; }
const std::string& Contact::getPhone() const { return Phone; }
const std::string& Contact::getDarkest() const { return Darkest; }

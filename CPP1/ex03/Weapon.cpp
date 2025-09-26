#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(std::string t) : type(t) {}

Weapon::Weapon(const Weapon& other)
{
	type = other.type;
}

Weapon& Weapon::operator=(const Weapon& other) {
	if (this != &other)
		type = other.type;
	return *this;
}

Weapon::~Weapon() {}

const std::string Weapon::getType() { return (type); }

void Weapon::setType(std::string t)
{
	type = t;
}

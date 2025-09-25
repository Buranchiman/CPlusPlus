#include "Weapon.hpp"

Weapon::Weapon() {}

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

#include "HumanA.hpp"

HumanA::HumanA(const std::string n, Weapon& w) : name(n), weapon(w) {}

HumanA::HumanA(const HumanA& other) : name (other.name), weapon(other.weapon) {}

HumanA& HumanA::operator=(const HumanA& other) {
	if (this != &other) {
		name = other.name;
		weapon = other.weapon;
	}
	return *this;
}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}

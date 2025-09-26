#include "HumanB.hpp"

HumanB::HumanB() : name("unknown"), weapon(NULL) {}

HumanB::HumanB(const std::string n) : name(n), weapon(NULL){}

HumanB::HumanB(const HumanB& other) {
	name = other.name;
	weapon = other.weapon;
}

HumanB& HumanB::operator=(const HumanB& other) {
	if (this != &other) {
		name = other.name;
		weapon = other.weapon;
	}
	return *this;
}

HumanB::~HumanB() {}

void HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (!weapon)
	{
		std::cout << "bare fists\n";
		return ;
	}
	else
		std::cout << weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}

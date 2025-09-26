#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon*		weapon;
public:
	HumanB();
	HumanB(const std::string n);
	HumanB(const HumanB& other);
	HumanB& operator=(const HumanB& other);
	~HumanB();

	void attack();
	void setWeapon(Weapon &w);
};

#endif

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string	name;
	Weapon&		weapon;
public:
	HumanA();
	HumanA(const std::string n, Weapon& w);
	HumanA(const HumanA& other);
	HumanA& operator=(const HumanA& other);
	~HumanA();

	void attack();
};

#endif

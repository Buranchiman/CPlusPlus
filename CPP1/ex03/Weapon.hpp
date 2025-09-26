#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string t);
	Weapon(const Weapon& other);
	Weapon& operator=(const Weapon& other);
	~Weapon();

	const std::string getType();
	void setType(std::string t);
};

#endif

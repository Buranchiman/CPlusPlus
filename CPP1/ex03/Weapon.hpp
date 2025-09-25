#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;
public:
	Weapon();
	Weapon(const Weapon& other);
	Weapon& operator=(const Weapon& other);
	~Weapon();

	const std::string getType();
	void setType();
};

#endif

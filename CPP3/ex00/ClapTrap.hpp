#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string const			name;
	unsigned int				hp;
	unsigned int				energy;
	unsigned int const			ad;
public:
	ClapTrap();
	ClapTrap(std::string n);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

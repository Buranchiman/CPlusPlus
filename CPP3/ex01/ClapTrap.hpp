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
	ClapTrap(std::string n, unsigned int h, unsigned int e, unsigned int const a);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	virtual void attack(const std::string& target);
	std::string const& getName(void) const;
	unsigned int getHp(void) const;
	unsigned int getEnergy(void) const;
	unsigned int getAd(void) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

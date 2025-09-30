#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n, 100, 100, 30)
{
	std::cout << "FragTrap constructor called for " << n << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	ClapTrap::attack(target);
	if (getEnergy() && getHp())
		std::cout << "FragTrap " << getName() << " attack " << target << ", causing " << getAd() << " points of damage" << std::endl;
	else
		std::cout << "FragTrap " << getName() << " is out of energy or hp" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " is ready to high five !" << std::endl;
}

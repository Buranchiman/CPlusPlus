#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called for " << n << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	ClapTrap::attack(target);
	if (getEnergy() && getHp())
		std::cout << "ScavTrap " << getName() << " attack " << target << ", causing " << getAd() << " points of damage" << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " is out of energy or hp" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " has entered gate keeper mode" << std::endl;
}

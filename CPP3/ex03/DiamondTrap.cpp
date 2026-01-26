#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default")
{
	setHp(100);
	setAd(30);
	setEnergy(50);
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const n) : ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n), name(n)
{
	setHp(100);
	setAd(30);
	setEnergy(50);
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor has been called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "This DiamondTrap is called " << name << " and its ClapTrap name is " << ClapTrap::getName() << std::endl;
}

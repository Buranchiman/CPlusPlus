#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Claptrap"), hp(10), energy(10), ad(0)
{
	std::cout << "Claptrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const n) : name(n), hp(10), energy(10), ad(0)
{
	std::cout << "Claptrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(std::string n, unsigned int h, unsigned int e, unsigned int const a) : name(n), hp(h), energy(e), ad(a)
{
	std::cout << "Claptrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hp(other.hp), energy(other.energy), ad(other.ad)
{
	std::cout << "Claptrap copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		energy = other.energy;
		ad = other.ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energy && hp)
	{
		energy--;
		std::cout << "ClapTrap " << name << " attack " << target << ", causing " << ad << " points of damage" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is out of energy or hp" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	tmp;
	tmp = hp - amount;
	if (tmp < 0)
		hp = 0;
	else
		hp = tmp;
	std::cout << "ClapTrap " << name << " has taken " << amount << " damage, ouch !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy && hp)
	{
		energy--;
		hp += amount;
		std:: cout << "ClapTrap " << name << " is repaired for " << amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is out of energy or hp" << std::endl;
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (energy);
}

unsigned int ClapTrap::getHp(void) const
{
	return (hp);
}

std::string const& ClapTrap::getName(void) const
{
	return (name);
}

unsigned int ClapTrap::getAd(void) const
{
	return (ad);
}

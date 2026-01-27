#include "Character.hpp"

Character::Character() : _name("Bob")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete(inventory[i]);
	}
}

std::string const& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << _name << " has equipped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << _name << " couldnt equipped " << m->getType()  << " inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	inventory[idx] = NULL;
				std::cout << _name << " has unequipped item in slot " << idx << " of inventory"  << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
}

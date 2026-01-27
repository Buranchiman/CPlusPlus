#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
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
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete(inventory[i]);
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] == NULL)
			{
				std::cout << "MateriaSource has learned " << m->getType() << std::endl;
				inventory[i] = m;
				return ;
			}
		}
		std::cout << "MateriaSource couldnt learn " << m->getType() << " inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
		{
			std::cout << "MateriaSource has created a clone of " << type << std::endl;
			return (inventory[i]->clone());
		}
	}
	std::cout << "MateriaSource couldnt create a clone of " << type << " isnt in inventory" << std::endl;
	return (NULL);
}

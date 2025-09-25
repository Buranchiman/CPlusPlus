#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie *z;
	try
	{
		z = new(Zombie);
		(*z).name = name;
		return (z);
	}
	catch(const std::bad_alloc)
	{
		std::cerr << "Allocation failed\n";
		return (NULL);
	}
}

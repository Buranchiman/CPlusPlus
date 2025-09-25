#include "Zombie.hpp"

Zombie::Zombie( void ) : name("") {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::Zombie(const Zombie &other)
{
	name = other.name;
}

Zombie& Zombie::operator=(const Zombie &other)
{
	if (this !=&other)
		name = other.name;
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed\n";
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...";
}

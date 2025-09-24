#include "Zombie.hpp"

Zombie::Zombie( void ) : name("") {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::Zombie(const Zombie &other)
{
	name = other.name;
}

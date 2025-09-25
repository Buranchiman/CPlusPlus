#include "Zombie.hpp"

int main(void)
{
	Zombie	z("dummy");
	int		n;
	Zombie*	horde;

	n = 3;
	horde = z.zombieHorde(n, "Brian");
	delete[](horde);
}

#include "Zombie.hpp"

int main(void)
{
	Zombie z("dummy");
	Zombie* heapster;

	heapster = z.newZombie("Heapster");
	z.randomChump("stackos");
	(*heapster).announce();
	delete(heapster);
}

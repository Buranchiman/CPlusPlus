#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap b("Bobby");
	ScavTrap a("Anna");

	for (int i = 0; i < 6; i++)
	{
		std::cout << i << "th time:\n";
		a.attack("Bobby");
		std::cout << a.getName() << " has " << a.getEnergy() << " left\n";
		b.takeDamage(20);
	}
	a.guardGate();
}

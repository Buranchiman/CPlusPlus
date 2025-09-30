#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap b("Bobby");
	ScavTrap a("Anna");

	for (int i = 0; i < 6; i++)
	{
		std::cout << i << "th time:\n";
		a.attack("Bobby");
		b.takeDamage(20);
	}
	a.guardGate();
}

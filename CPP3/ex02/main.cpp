#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap b("Bobby");
	ScavTrap a("Anna");
	FragTrap c("Chris");

	for (int i = 0; i < 6; i++)
	{
		std::cout << i << "th time:\n";
		a.attack("Bobby");
		b.takeDamage(20);
		c.attack("Bobby");
		std::cout << c.getName() << " has " << c.getEnergy() << " left\n";
		b.takeDamage(30);
	}
	a.guardGate();
	c.highFivesGuys();
}

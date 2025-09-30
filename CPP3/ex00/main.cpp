#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap b("Bobby");
	ClapTrap a("Anna");

	for (int i = 0; i < 13; i++)
	{
		std::cout << i << "th time:\n";
		a.attack("Bobby");
		b.takeDamage(3);
		b.beRepaired(1);
	}
}

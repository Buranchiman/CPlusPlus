#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap j("Josuke");
	DiamondTrap k("Kira");

	k.guardGate();
	j.highFivesGuys();
	std::cout << "Kira has " << k.getEnergy() << " energy left\n";
	k.attack("Josuke");
	std::cout << "Kira has " << k.getEnergy() << " energy left\n";
	j.whoAmI();
	k.whoAmI();
}

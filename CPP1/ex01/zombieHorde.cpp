#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* horde;

	try
	{
		horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			(*(horde + i)).name = name;
		return (horde);
	}
	catch(const std::bad_alloc)
	{
		std::cerr << "Allocation failed\n";
		return (NULL);
	}
}

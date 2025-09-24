#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie(void);
	Zombie(std::string name);
	Zombie(const Zombie &other);
	Zombie &operator=(const Zombie &other);
	~Zombie(void);

	void announcce ( void );
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
};

#endif

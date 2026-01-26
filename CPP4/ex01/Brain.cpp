#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[35mBrain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i =0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "\033[35mBrain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i =0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "\033[35mBrain assignment called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[35mBrain destructor called" << std::endl;
}

void Brain::thinkAbout(std::string idea)
{
	for (int i =0; i < 100; i++)
		ideas[i] = idea;
}

void Brain::comesToMind()
{
	std::cout << "first thing that comes to mind is " << ideas[0] << " and it is at " << &ideas[0] << std::endl;
}

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		brain = other.brain;
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	delete(brain);
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meoooow" << std::endl;
}

void Cat::fillBrain(std::string idea)
{
	brain->thinkAbout(idea);
}

void Cat::showsIdea()
{
	brain->comesToMind();
}

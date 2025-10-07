#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		brain = other.brain;
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog()
{
	delete(brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

void Dog::fillBrain(std::string idea)
{
	brain->thinkAbout(idea);
}

void Dog::showsIdea()
{
	brain->comesToMind();
}

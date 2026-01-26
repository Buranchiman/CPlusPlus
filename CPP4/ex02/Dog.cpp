#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "\033[31mDog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "\033[31mDog copy constructor called" << std::endl;
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
	std::cout << "\033[31mDog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "\033[31mWoof! Woof!" << std::endl;
}

void Dog::fillBrain(std::string idea)
{
	brain->thinkAbout(idea);
}

void Dog::showsIdea()
{
	brain->comesToMind();
}

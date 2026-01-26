#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "\033[31mDog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "\033[31mDog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[31mDog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "\033[31mWoof! Woof!" << std::endl;
}

#include "Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string t) : type(t)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*Random animal noises*" << std::endl;
}

std::string Animal::getType() const { return (type); }

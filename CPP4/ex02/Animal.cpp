#include "Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout << "\033[33mAnimal default constructor called" << std::endl;
}

Animal::Animal(std::string t) : type(t)
{
	std::cout << "\033[33mAnimal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "\033[33mAnimal copy constructor called" << std::endl;
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
	std::cout << "\033[33mAnimal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "\033[33m*Random animal noises*" << std::endl;
}

std::string Animal::getType() const { return (type); }

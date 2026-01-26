#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "\033[37mWrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t) : type(t)
{
	std::cout << "\033[37mWrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "\033[37mWrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[37mWrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[37m*Random WrongAnimal noises*" << std::endl;
}

std::string WrongAnimal::getType() const { return (type); }

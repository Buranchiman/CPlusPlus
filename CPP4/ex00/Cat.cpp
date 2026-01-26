#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "\033[34mCat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "\033[34mCat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "\033[34mCat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "\033[34mMeoooow" << std::endl;
}

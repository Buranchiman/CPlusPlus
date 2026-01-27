#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "\033[34mCat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "\033[34mCat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		delete brain;
		brain = new(Brain);
		*brain = *other.brain;
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	delete(brain);
	std::cout << "\033[34mCat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "\033[34mMeoooow" << std::endl;
}

void Cat::fillBrain(std::string idea)
{
	brain->thinkAbout(idea);
}

void Cat::showsIdea()
{
	brain->comesToMind();
}

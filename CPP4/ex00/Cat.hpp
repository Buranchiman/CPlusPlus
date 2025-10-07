#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : virtual public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	virtual void makeSound() const;
};

#endif

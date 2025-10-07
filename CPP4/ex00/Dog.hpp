#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	virtual void makeSound() const;
};

#endif

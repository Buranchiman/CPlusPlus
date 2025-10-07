#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void fillBrain(std::string idea);
	void showsIdea();
	virtual void makeSound() const;
};

#endif

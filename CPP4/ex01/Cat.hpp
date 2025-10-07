#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	virtual void makeSound() const;
	void fillBrain(std::string idea);
	void showsIdea();
};

#endif

#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string t);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif

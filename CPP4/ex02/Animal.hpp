#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>

class Animal
{
protected:
	Animal();
	Animal(std::string t);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	std::string type;
public:
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif

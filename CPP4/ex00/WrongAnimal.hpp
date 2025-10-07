#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string t);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif

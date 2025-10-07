#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	~WrongCat();

	virtual void makeSound() const;
};

#endif

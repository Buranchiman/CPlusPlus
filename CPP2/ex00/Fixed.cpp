#include "Fixed.hpp"

Fixed::Fixed() : value(0), fract(8)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : fract(8)
{
	std::cout << "Copy constructor called\n";
	value = other.value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		value = other.value;
		std::cout << "Copy assignment operator called\n";
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (value);
}

void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called\n";
	value = raw;
}

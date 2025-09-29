#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called\n";
	value = integer << fract;
}

Fixed::Fixed(const float decimal)
{
	std::cout << "Float constructor called\n";
	value = roundf(decimal * (1 << fract));
}

Fixed::Fixed(const Fixed& other)
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

float Fixed::toFloat( void ) const
{
	return (float)value / (1 << fract);
}

int Fixed::toInt( void ) const
{
	return (value >> fract);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int integer)
{
	value = integer << fract;
}

Fixed::Fixed(const float decimal)
{
	value = roundf(decimal * (1 << fract));
}

Fixed::Fixed(const Fixed& other)
{
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

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const
{
	return (value);
}

void Fixed::setRawBits( int const raw)
{
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

bool Fixed::operator<(const Fixed& other)
{
	return (this->value < other.value);
}

bool Fixed::operator>(const Fixed& other)
{
	return (this->value > other.value);
}

bool Fixed::operator<=(const Fixed& other)
{
	return (this->value <= other.value);
}

bool Fixed::operator>=(const Fixed& other)
{
	return (this->value >= other.value);
}

bool Fixed::operator==(const Fixed& other)
{
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other)
{
	return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->value + other.value);
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->value - other.value);
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;
	long long tmp = static_cast<long long>(this->value * other.value);
	res.setRawBits(static_cast<int>(tmp >> 8));
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;
	long long tmp = (static_cast<long long>(this->value) << fract) / other.value;
	res.setRawBits(static_cast<int>(tmp));
	return (res);
}

Fixed& Fixed::operator++()
{
	++value;
	return (*this);
}

Fixed& Fixed::operator--() {
	--value;
	return (*this);
}


Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++value;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--value;
	return (old);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b) ? a:b;
}

const Fixed& Fixed::min(const Fixed&a , const Fixed&b)
{
	Fixed	cpa(a);
	Fixed	cpb(b);
	return (cpa <= cpb) ? a:b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b) ? a:b;
}

const Fixed& Fixed::max(const Fixed&a , const Fixed&b)
{
	Fixed	cpa(a);
	Fixed	cpb(b);
	return (cpa >= cpb) ? a:b;
}

#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int			value;
	static const int	fract = 8;
public:
	Fixed();
	Fixed(const int integer);
	Fixed(const float decimal);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif

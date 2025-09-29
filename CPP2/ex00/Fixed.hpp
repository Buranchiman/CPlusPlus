#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

class Fixed {
private:
	int			value;
	const int	fract;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif

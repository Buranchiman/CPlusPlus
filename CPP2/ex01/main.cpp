#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed minInt(-8388608);
	Fixed maxInt(8388607);
	a = Fixed( 1234.4321f );

	std::cout << "\033[33mSUBJECT TESTS-------------" <<std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "END OF SUBJECT TESTS-------------\033[37m" <<std::endl;
	std::cout << "\033[35mCUSTOM TESTS-------------" <<std::endl;
	std::cout << "minInt is " << minInt.toInt() << " as integer" << std::endl;
	std::cout << "maxInt is " << maxInt.toInt() << " as integer" << std::endl;
	std::cout << "END OF CUSTOM TESTS-------------\033[37m" <<std::endl;
	return 0;
}

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	std::cout << "\033[33mSUBJECT TESTS-------------" <<std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "Max is " << Fixed::max( a, b ) << std::endl;
	std::cout << "END OF SUBJECT TESTS-------------\033[37m" <<std::endl;
	std::cout << "\033[35mCUSTOM TESTS-------------" <<std::endl;
	std::cout << "Min is " << Fixed::min( a, b ) << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << b + a << std::endl;
	std::cout << b - a << std::endl;
	std::cout << "END OF SUBJECT TESTS-------------\033[37m" <<std::endl;
	return (0);
}

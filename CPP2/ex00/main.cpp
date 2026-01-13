#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << "\033[33mSUBJECT TESTS-------------" <<std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	a.setRawBits(8);
	std::cout << a.getRawBits() << std::endl;
	std::cout << "END OF SUBJECT TESTS-------------\033[37m" <<std::endl;
	std::cout << "\033[35mCUSTOM TESTS-------------" <<std::endl;
	a.setRawBits(2147483647);
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(-2147483648);
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(-0);
	std::cout << a.getRawBits() << std::endl;
	std::cout << "END OF CUSTOM TESTS-------------\033[37m" <<std::endl;
	return 0;
}

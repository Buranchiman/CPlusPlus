#include "Point.hpp"

Fixed cross( Point const a, Point const b, Point const c )
{
	return (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed c1;
	Fixed c2;
	Fixed c3;

	c1 = cross(a, b, point);
	c2 = cross(b, c, point);
	c3 = cross(c, a, point);
	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
		return (true);
	return (false);
}

int main( void )
{
	Point const a(-2, -2);
	Point const b(3, 3);
	Point const c(7, 7);
	Point point(1 , 1);
	Point point2(33, 33);
	bool res = bsp(a, b, c, point);
	std::cout << "result of bsp for point is " << res << std::endl;
	res = bsp(a, b, c, point2);
	std::cout << "result of bsp for point2 is " << res << std::endl;
	return (0);
}

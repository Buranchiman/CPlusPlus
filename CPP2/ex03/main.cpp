#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed minX;
	Fixed minY;
	Fixed maxX;
	Fixed maxY;

	minX = Fixed::min(a.getX(), b.getX());
	if (minX > c.getX())
		minX = c.getX();
	maxX = Fixed::max(a.getX(), b.getX());
	if (maxX < c.getX())
		maxX = c.getX();
	minY = Fixed::min(a.getY(), b.getY());
	if (minY > c.getY())
		minY = c.getY();
	maxY = Fixed::max(a.getY(), b.getY());
	if (maxX < c.getY())
		maxX = c.getY();
	if (minX > point.getX() || maxX < point.getX() || minY > point.getY() || )
	return (true);
}

int main( void )
{
	Point const a(-2, 2);
	Point const b(1, 3);
	Point const c(-7, 4);
	Point point(1 , 1);
	bsp(a, b, c, point);
	return (0);
}

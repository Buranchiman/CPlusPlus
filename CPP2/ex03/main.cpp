#include "Point.hpp"

Fixed cross(Point const a, Point const b, Point const c)
{
	return (b.getX() - a.getX()) * (c.getY() - a.getY())
			- (b.getY() - a.getY()) * (c.getX() - a.getX());
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed c1;
	Fixed c2;
	Fixed c3;

	Fixed area = cross(a, b, c);
	if (area == 0)
	{
		std::cout << "Triangle invalid\n";
		return (false);
	}
	c1 = cross(a, b, point);
	c2 = cross(b, c, point);
	c3 = cross(c, a, point);
	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
		return (true);
	return (false);
}

int main( void )
{
	Point const a(0, 0);
	Point const b(10, 0);
	Point const c(3, 7);
	Point point(1 , 1);
	Point point2(33, 33);
	Point edge(1, 0);
	Point vertex(3, 7);

	bool in = bsp(a, b, c, point);
	std::cout << "point is " << (in ? "inside" : "outside") << std::endl;
	in = bsp(a, b, c, point2);
	std::cout << "point2 is " << (in ? "inside" : "outside") << std::endl;
	in = bsp(a, b, c, edge);
	std::cout << "edge is " << (in ? "inside" : "outside") << std::endl;
	in = bsp(a, b, c, vertex);
	std::cout << "vertex is " << (in ? "inside" : "outside") << std::endl;
	return (0);
}

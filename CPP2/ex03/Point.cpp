#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float xvalue, float yvalue) : x(Fixed(xvalue)), y(Fixed(yvalue)) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

Fixed const& Point::getX() const
{
	return (x);
}

Fixed const& Point::getY() const
{
	return (y);
}

Point::~Point() {}

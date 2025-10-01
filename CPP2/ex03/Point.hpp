#ifndef Point_HPP
#define Point_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(float xvalue, float yvalue);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Fixed const& getX() const;
	Fixed const& getY() const;
};

#endif

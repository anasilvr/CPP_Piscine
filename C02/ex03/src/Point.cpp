
#include "../include/Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) { return; }

Point::Point(float const initX, float const initY) : _x(initX), _y(initY) { 
	return;
}

// Copy constructor
Point::Point(const Point &other) {
  *this = other;
  return;
}

// Copy assignment overload
Point &Point::operator=(const Point &rhs) {
	if (this != &rhs){
		_x = rhs._x;
		_y = rhs._y;
	}
	return *this;
}

// Default destructor
Point::~Point() { return; }

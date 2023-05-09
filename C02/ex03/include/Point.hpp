#pragma once

#include "../include/Fixed.hpp"
// Class declaration
class Point {
	public:
		Point();
		Point(float const initX, float const initY);
		Point(const Point &other);
		Point &operator=(const Point &rhs);
		~Point();

	private:
		Fixed const _x;
		Fixed const _y;

};

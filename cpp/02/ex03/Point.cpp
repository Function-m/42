#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(float const xVal, float const yVal) : x(xVal), y(yVal) {}
Point::Point(Point const& src) : x(src.x), y(src.y) {}
Point::~Point() {}

Point& Point::operator=(Point const& rhs) {
  (void)rhs;
  return *this;
}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }

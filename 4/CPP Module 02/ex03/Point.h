#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
 private:
  Fixed const x;
  Fixed const y;

 public:
  Point();
  Point(float const x, float const y);
  Point(Point const& src);
  ~Point();

  Point& operator=(Point const& rhs);

  Fixed getX() const;
  Fixed getY() const;
};

#endif

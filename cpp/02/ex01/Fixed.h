#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
 private:
  int fixedPointValue;
  static const int fractionalBits = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(const int raw);

  // The following contents have been added.
  Fixed(const int intVal);
  Fixed(const float floatVal);

  float toFloat(void) const;
  int toInt(void) const;
};

// The following has been added.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

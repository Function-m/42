#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
 private:
  int fixedPointValue;
  static const int fractionalBits = 8;

 public:
  Fixed();
  Fixed(const int intVal);
  Fixed(const float floatVal);
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits(void) const;
  void setRawBits(const int raw);
  float toFloat(void) const;
  int toInt(void) const;

  // The following contents have been added.
  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  Fixed& operator++();
  Fixed& operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

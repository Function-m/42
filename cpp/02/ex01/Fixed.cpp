#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)  // This has been changed.
    this->fixedPointValue = other.fixedPointValue;
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
  fixedPointValue = raw;
}

// The following contents have been added.
Fixed::Fixed(const int intVal) : fixedPointValue(intVal << fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal) : fixedPointValue(roundf(floatVal * (1 << fractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
  return fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  return os << fixed.toFloat();
}

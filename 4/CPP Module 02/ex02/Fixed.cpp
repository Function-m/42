#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) : fixedPointValue(intVal << fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal) : fixedPointValue(roundf(floatVal * (1 << fractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->fixedPointValue = other.fixedPointValue;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
  fixedPointValue = raw;
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

// The following contents have been added.
bool Fixed::operator>(const Fixed& other) const { return this->fixedPointValue > other.fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return this->fixedPointValue < other.fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return this->fixedPointValue >= other.fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return this->fixedPointValue <= other.fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return this->fixedPointValue == other.fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return this->fixedPointValue != other.fixedPointValue; }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed& Fixed::operator++() {
  this->fixedPointValue++;
  return *this;
}

Fixed& Fixed::operator--() {
  this->fixedPointValue--;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  operator++();
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  operator--();
  return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
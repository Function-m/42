#include <iostream>
#include "Fixed.h"

int main(void) {
  // Default constructor called
  Fixed a;
  // Int constructor called
  Fixed const b(10);
  // Float constructor called
  Fixed const c(42.42f);
  // Copy constructor called
  // Copy assignment operator called
  Fixed const d(b);

  // Float constructor called
  // Copy assignment operator called
  // Destructor called
  a = Fixed(1234.4321f);

  // a is 1234.43
  std::cout << "a is " << a << std::endl;
  // b is 10
  std::cout << "b is " << b << std::endl;
  // c is 42.4219
  std::cout << "c is " << c << std::endl;
  // d is 10
  std::cout << "d is " << d << std::endl;

  // a is 1234 as integer
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  // b is 10 as integer
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  // c is 42 as integer
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  // d is 10 as integer
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  // Destructor called
  // Destructor called
  // Destructor called
  // Destructor called
  return 0;
}

#include "Fixed.h"
#include <iostream>
#include <iomanip>

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  //0
  std::cout << a << std::endl;
  //0.00390625
  std::cout << ++a << std::endl;
  //0.00390625 
  std::cout << a << std::endl;
  //0.00390625 
  std::cout << a++ << std::endl;
  //0.0078125 
  std::cout << a << std::endl;

  //10.1016 
  std::cout << b << std::endl;
  //10.1016
  std::cout << Fixed::max(a, b) << std::endl;

  return 0;
}

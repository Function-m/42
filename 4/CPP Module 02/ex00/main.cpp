#include <iostream>
#include "Fixed.h"

#ifdef ANOTHER_TEST
int main(void) {
  std::cout << "\n* Default Constructor and getRawBits *" << std::endl;
  Fixed a;
  std::cout << a.getRawBits() << std::endl;

  std::cout << "\n* Copy Constructor *" << std::endl;
  Fixed b(a);
  std::cout << b.getRawBits() << std::endl;

  std::cout << "\n* Copy Assignment Operator *" << std::endl;
  Fixed c;
  c = b;
  std::cout << c.getRawBits() << std::endl;

  std::cout << "\n* setRawBits and getRawBits *" << std::endl;
  a.setRawBits(123);
  std::cout << a.getRawBits() << std::endl;

  std::cout << "\n* dynamic creation and destruction *" << std::endl;
  Fixed* d = new Fixed;
  std::cout << d->getRawBits() << std::endl;
  delete d;

  std::cout << std::endl;
  return 0;
}
#else
int main(void) {
  // Default constructor called
  Fixed a;
  // Copy constructor called
  // Copy assignment operator called
  // getRawBits member function called
  Fixed b(a);
  // Default constructor called
  Fixed c;

  // Copy assignment operator called
  // getRawBits member function called
  c = b;

  // getRawBits member function called
  // 0
  std::cout << a.getRawBits() << std::endl;
  // getRawBits member function called
  // 0
  std::cout << b.getRawBits() << std::endl;
  // getRawBits member function called
  // 0
  std::cout << c.getRawBits() << std::endl;

  // Destructor called
  // Destructor called
  // Destructor called
  return 0;
}
#endif

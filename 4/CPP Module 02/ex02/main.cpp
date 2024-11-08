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

// #include "Fixed.h"
// #include <iostream>
// #include <iomanip>

// int main(void)
// {
//   Fixed a;
//   Fixed b(Fixed(5.05f) * Fixed(2));
//   Fixed c(2.34f);
//   Fixed d = c; // 복사 할당
//   Fixed e;

//   // 초기 값 테스트
//   std::cout << "Initial value of a: " << a << std::endl;
//   std::cout << "Value of b (5.05 * 2): " << b << std::endl;
//   std::cout << "Value of c: " << c << std::endl;
//   std::cout << "Value of d (copy of c): " << d << std::endl;

//   // 사전 증가 및 감소 테스트
//   std::cout << "++a: " << ++a << std::endl;
//   std::cout << "--a: " << --a << std::endl;

//   // 사후 증가 및 감소 테스트
//   std::cout << "a++: " << a++ << std::endl;
//   std::cout << "a--: " << a-- << std::endl;

//   // 산술 연산자 테스트
//   e = a + b;
//   std::cout << "a + b: " << e << std::endl;
//   e = b - a;
//   std::cout << "b - a: " << e << std::endl;
//   e = a * b;
//   std::cout << "a * b: " << e << std::endl;
//   e = b / Fixed(2.0f);
//   std::cout << "b / 2.0: " << e << std::endl;

//   // 비교 연산자 테스트
//   std::cout << "a > b: " << (a > b) << std::endl;
//   std::cout << "a < b: " << (a < b) << std::endl;
//   std::cout << "a >= b: " << (a >= b) << std::endl;
//   std::cout << "a <= b: " << (a <= b) << std::endl;
//   std::cout << "c == d: " << (c == d) << std::endl;
//   std::cout << "a != b: " << (a != b) << std::endl;

//   // min/max 함수 테스트
//   std::cout << "Min of a, b: " << Fixed::min(a, b) << std::endl;
//   std::cout << "Max of a, b: " << Fixed::max(a, b) << std::endl;

//   return 0;
// }

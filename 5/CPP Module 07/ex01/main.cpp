#include <iostream>

#include "iter.hpp"

int main() {
  // 정수 배열 테스트
  int intArray[] = {1, 2, 3, 4, 5};
  int length = 5;

  std::cout << "\n* Original intArray *\n";
  iter(intArray, length, testPrintingElement);

  iter(intArray, length, testIncrementingElement);

  std::cout << "\n* Incremented intArray *\n";
  iter(intArray, length, testPrintingElement);

  // 문자열 배열 테스트
  std::string strArray[] = {"Hello", "World", "C++", "Templates"};
  length = 4;

  std::cout << "\n* Original strArray *\n";
  iter(strArray, length, testPrintingElement);

  return 0;
}

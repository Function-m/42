#include <iostream>
#include <vector>

#include "easyfind.h"

// * vetor에 관해서
//  1. 동적 크기 조절
//  2. 배열 인덱스와 비슷한 임의 접근
//  3. 연속적인 메모리 할당
//  4. 중간 요소 삭제 및 삽입 가능 (단, 삭제 시 메모리 재배열)

int main() {
  
  std::vector<int> vec;
  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }

  try {
    std::vector<int>::iterator it = easyfind(vec, 5);
    std::cout << "Value found: " << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::vector<int>::iterator it = easyfind(vec, 10);
    std::cout << "Value found: " << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

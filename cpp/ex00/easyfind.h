#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <iterator>
#include <stdexcept>

// * it은 iterator의 약자로써 자주 사용된다.
// * iterator는 컨테이너의 원소를 가리키는 포인터와 같은 역할을 한다.
//  하지만 실제 포인터와 다르게 컨테이너의 요소가 삭제된 걸 감지하는 안정성을 제공하거나,
//  직접 메모리 주소를 다루지 않고 추상화된 접근 방법을 제공하기에 내부적으로 컨테이너의 구현 방식에 종속되지 않는다.
template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw std::runtime_error("Value not found in container");
  }
  return it;
}

#endif  // EASYFIND_H
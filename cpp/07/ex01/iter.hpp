#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Required by the subject

template <class T>
void iter(T* array, size_t length, void (*f)(T&)) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

// For tests

template <typename T>
void testPrintingElement(T& element) {
  std::cout << element << std::endl;
}

template <typename T>
void testIncrementingElement(T& element) {
  element++;
}

#endif  // ITER_HPP
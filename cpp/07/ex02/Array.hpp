#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>

// You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.

template <typename T>
class Array {
 private:
  T* elements;
  unsigned int length;

 public:
  // Construction with no parameter: Creates an empty array.
  Array() : elements(NULL), length(0) {}
  
  // Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
  Array(unsigned int n) : elements(new T[n]()), length(n) {}

  //  Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
  Array(const Array& other) : elements(new T[other.size()]()), length(other.size()) {
    for (unsigned int i = 0; i < length; ++i) {
      elements[i] = other.elements[i];
    }
  }

  ~Array() {
    delete[] elements;
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      delete[] elements;
      length = other.size();
      elements = new T[length]();
      for (unsigned int i = 0; i < length; ++i) {
        elements[i] = other.elements[i];
      }
    }
    return *this;
  }

  // Elements can be accessed through the subscript operator: [ ].
  // When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
  T& operator[](unsigned int index) {
    if (index >= length) {
      throw std::out_of_range("Index out of range");
    }
    return elements[index];
  }
  const T& operator[](unsigned int index) const {
    if (index >= length) {
      throw std::out_of_range("Index out of range");
    }
    return elements[index];
  }
  T& operator[](int index) {
    if (index < 0 || static_cast<unsigned int>(index) >= length) {
      throw std::out_of_range("Index out of range");
    }
    return elements[index];
  }
  const T& operator[](int index) const {
    if (index < 0 || static_cast<unsigned int>(index) >= length) {
      throw std::out_of_range("Index out of range");
    }
    return elements[index];
  }

  // A member function size() that returns the number of elements in the array. This member function takes no parameter and musn’t modify the current instance.
  unsigned int size() const {
    return length;
  }
};

#endif  // ARRAY_HPP

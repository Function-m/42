#include "Brain.h"

#include <iostream>

Brain::Brain() {
  std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain& src) {
  for (int i = 0; i < IDEAS_SIZE; ++i)
    this->ideas[i] = src.ideas[i];
  std::cout << "Brain created using copy constructor." << std::endl;
}

Brain::~Brain() {
  std::cout << "Brain destroyed." << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
  if (this != &rhs) {
    for (int i = 0; i < IDEAS_SIZE; ++i)
      this->ideas[i] = rhs.ideas[i];
    std::cout << "Brain assigned using copy assignment." << std::endl;
  } else {
    std::cout << "Self-assignment avoided for Brain." << std::endl;
  }
  return *this;
}

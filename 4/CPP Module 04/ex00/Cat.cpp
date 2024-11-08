#include "Cat.h"

Cat::Cat() {
  this->type = "Cat";
  std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
}

Cat::~Cat() {
  std::cout << "Cat destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
  Animal::operator=(rhs);
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow!" << std::endl;
}

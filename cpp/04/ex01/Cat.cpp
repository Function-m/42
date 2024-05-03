#include "Cat.h"

#include <iostream>

Cat::Cat() {
  brain = new Brain();
  this->type = "Cat";
  std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
  brain = new Brain(*src.brain);
}

Cat::~Cat() {
  delete brain;
  std::cout << "Cat destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
  Animal::operator=(rhs);
  if (brain != rhs.brain)
    *brain = *rhs.brain;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Bark!" << std::endl;
}

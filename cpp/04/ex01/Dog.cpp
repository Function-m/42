#include <iostream>

#include "Dog.h"

Dog::Dog() {
  brain = new Brain();
  this->type = "Dog";
  std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
  brain = new Brain(*src.brain);
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
  Animal::operator=(rhs);
  if (brain != rhs.brain)
    *brain = *rhs.brain;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Bark!" << std::endl;
}

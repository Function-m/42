#include "Animal.h"

Animal::Animal() : type("") {
  std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal& src) : type(src.type) {
  std::cout << "Animal created using copy constructor. Copied type: '" << type << "'." << std::endl;
}

Animal::~Animal() {
  std::cout << "Animal destroyed." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
    std::cout << "Animal assigned using copy assignment. New type: '" << type << "'." << std::endl;
  } else {
    std::cout << "Self-assignment avoided for Animal of type '" << type << "'." << std::endl;
  }
  return *this;
}

void Animal::makeSound() const {
  std::cout << "Animal makes a sound." << std::endl;
}

std::string Animal::getType() const {
  return type;
}

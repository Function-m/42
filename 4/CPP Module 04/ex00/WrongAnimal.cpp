#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("") {
  std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {
  std::cout << "WrongAnimal created using copy constructor. Copied type: '" << type << "'." << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destroyed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
    std::cout << "WrongAnimal assigned using copy assignment. New type: '" << type << "'." << std::endl;
  } else {
    std::cout << "Self-assignment avoided for WrongAnimal of type '" << type << "'." << std::endl;
  }
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal makes a sound." << std::endl;
}

std::string WrongAnimal::getType() const {
  return type;
}

#include "WrongCat.h"

WrongCat::WrongCat() {
  this->type = "WrongCat";
  std::cout << "WrongCat created." << std::endl;

}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destroyed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
  WrongAnimal::operator=(rhs);
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat makes a wrong sound" << std::endl;
}

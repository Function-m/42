#include "Dog.h"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog& src) : AAnimal(src) {
    *this = src;
}

Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    AAnimal::operator=(rhs);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Bark!" << std::endl;
}

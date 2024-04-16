#include "Dog.h"
#include <iostream>

Dog::Dog() {
    brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
    brain = new Brain(*src.brain);
    std::cout << "Dog copied." << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        *brain = *rhs.brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Bark!" << std::endl;
}

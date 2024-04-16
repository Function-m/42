#include "Animal.h"

Animal::Animal() : type("") {
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal& src) {
    *this = src;
    std::cout << "Animal copied." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound." << std::endl;
}

std::string Animal::getType() const {
    return type;
}

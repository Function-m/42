#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

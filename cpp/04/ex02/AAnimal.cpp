#include "AAnimal.h"

AAnimal::AAnimal() : type("") {
    std::cout << "AAnimal created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) : type(src.type) {
    std::cout << "AAnimal copied." << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}

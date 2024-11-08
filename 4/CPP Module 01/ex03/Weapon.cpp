#include "Weapon.h"

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& newType) {
    type = newType;
}

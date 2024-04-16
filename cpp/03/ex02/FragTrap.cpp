#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap " << this->name << " is copied." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " is destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    ClapTrap::operator=(rhs);
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " requests a high five." << std::endl;
}

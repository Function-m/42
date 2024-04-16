#include "DiamondTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src), name(src.name) {
    std::cout << "DiamondTrap " << this->name << " is copied." << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " is destroyed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    ClapTrap::operator=(rhs);
    FragTrap::operator=(rhs);
    ScavTrap::operator=(rhs);
    this->name = rhs.name;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->name << ", and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
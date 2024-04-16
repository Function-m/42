#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap " << this->name << " is copied." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " is destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    ClapTrap::operator=(rhs);
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout <<
    "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

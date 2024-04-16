#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage) {
    std::cout << "ClapTrap " << this->name << " is copied." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " is destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
    }
    std::cout << "ClapTrap " << this->name << " is assigned." << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->name << " cannot attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints > 0) {
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        this->hitPoints -= amount;
    } else {
        std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->name << " cannot repair itself." << std::endl;
    }
}

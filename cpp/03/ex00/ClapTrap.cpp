#include "ClapTrap.h"

#include <iomanip>
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  updateOldStatus();
  printStatus();
  std::cout << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage) {
  updateOldStatus();
  printStatus();
  std::cout << " is copied." << std::endl;
}

ClapTrap::~ClapTrap() {
  printStatus();
  std::cout << " is destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
  if (this != &rhs) {
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
  }
  printStatus();
  std::cout << " is copy assigned." << std::endl;
  return *this;
}

void ClapTrap::attack(const std::string& target) {
  if (this->energyPoints > 0 && this->hitPoints > 0) {
    this->energyPoints--;
    printStatus();
    std::cout << " attacks " << COLOR_GREEN(target) << ", causing " << COLOR_BLUE(this->attackDamage) << " points of damage!" << std::endl;
  } else {
    printStatus();
    std::cout << " cannot attack." << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints > 0) {
    this->hitPoints -= (this->hitPoints > amount) ? amount : this->hitPoints;
    printStatus();
    std::cout << " takes " << COLOR_BLUE(amount) << " points of damage!" << std::endl;
  } else {
    printStatus();
    std::cout << "'s health point is already zero." << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energyPoints > 0 && this->hitPoints > 0) {
    this->hitPoints += amount;
    this->energyPoints--;
    printStatus();
    std::cout << " repairs itself, regaining " << COLOR_BLUE((amount)) << " hit points!" << std::endl;
  } else {
    printStatus();
    std::cout << " cannot be repaired." << std::endl;
  }
}

void ClapTrap::updateOldStatus() {
  oldHitPoints = hitPoints;
  oldEnergyPoints = energyPoints;
  oldAttackDamage = attackDamage;
}

void ClapTrap::coloredValue(unsigned int currentValue, unsigned int oldValue) const {
  if (currentValue != oldValue)
    std::cout << ANSI_BLUE;
  std::cout << std::setw(2) << currentValue << ANSI_RESET;
}

void ClapTrap::printStatus() {
  std::cout << "ClapTrap " << COLOR_GREEN(this->name);
  std::cout << " (HP: ";
  coloredValue(this->hitPoints, this->oldHitPoints);
  std::cout << " | EP: ";
  coloredValue(this->energyPoints, this->oldEnergyPoints);
  std::cout << " | DMG: ";
  coloredValue(this->attackDamage, this->oldAttackDamage);
  std::cout << ")";

  updateOldStatus();
}
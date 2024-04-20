#include "ScavTrap.h"

#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->hitPoints = 100;
  this->energyPoints = 50;
  this->attackDamage = 20;
  updateOldStatus();
  printStatus();
  std::cout << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
  updateOldStatus();
  printStatus();
  std::cout << " is copied." << std::endl;
}

ScavTrap::~ScavTrap() {
  printStatus();
  std::cout << " is destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
  ClapTrap::operator=(rhs);
  return *this;
}

void ScavTrap::attack(const std::string& target) {  
  if (this->energyPoints > 0 && this->hitPoints > 0) {
    this->energyPoints--;
    printStatus();
    std::cout << " attacks " << COLOR_GREEN(target) << ", causing " << COLOR_BLUE(this->attackDamage) << " points of damage!" << std::endl;
  } else {
    printStatus();
    std::cout << " cannot attack." << std::endl;
  }
}

void ScavTrap::guardGate() {
  printStatus();
  std::cout << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::printStatus() {
  std::cout << "ScavTrap " << COLOR_RED(this->name);
  std::cout << " (HP: ";
  coloredValue(this->hitPoints, this->oldHitPoints);
  std::cout << " | EP: ";
  coloredValue(this->energyPoints, this->oldEnergyPoints);
  std::cout << " | DMG: ";
  coloredValue(this->attackDamage, this->oldAttackDamage);
  std::cout << ")";

  updateOldStatus();
}

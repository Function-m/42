#include "FragTrap.h"

#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->hitPoints = 100;
  this->energyPoints = 100;
  this->attackDamage = 30;
  updateOldStatus();
  printStatus();
  std::cout << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
  updateOldStatus();
  printStatus();
  std::cout << " is copied." << std::endl;
}

FragTrap::~FragTrap() {
  printStatus();
  std::cout << " is destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
  ClapTrap::operator=(rhs);
  return *this;
}

void FragTrap::highFivesGuys(void) {
  printStatus();
  std::cout << " requests a high five." << std::endl;
}

void FragTrap::printStatus() {
  std::cout << "FragTrap " << COLOR_YELLOW(this->name);
  std::cout << " (HP: ";
  coloredValue(this->hitPoints, this->oldHitPoints);
  std::cout << " | EP: ";
  coloredValue(this->energyPoints, this->oldEnergyPoints);
  std::cout << " | DMG: ";
  coloredValue(this->attackDamage, this->oldAttackDamage);
  std::cout << ")";

  updateOldStatus();
}

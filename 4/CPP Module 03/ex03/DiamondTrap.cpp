#include "DiamondTrap.h"

#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
  this->hitPoints = FragTrap::hitPoints;
  this->energyPoints = ScavTrap::energyPoints;
  this->attackDamage = FragTrap::attackDamage;
  std::cout << ANSI_MAGENTA << "DiamondTrap " << this->name << " is created." << ANSI_RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src), name(src.name) {
  std::cout << ANSI_MAGENTA << "DiamondTrap " << this->name << " is copied." << ANSI_RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << ANSI_MAGENTA << "DiamondTrap " << this->name << " is destroyed." << ANSI_RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
  ClapTrap::operator=(rhs);
  FragTrap::operator=(rhs);
  ScavTrap::operator=(rhs);
  this->name = rhs.name;
  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << ANSI_MAGENTA << "I am DiamondTrap " << this->name << ", and my ClapTrap name is " << ClapTrap::name << "." << ANSI_RESET << std::endl;
}
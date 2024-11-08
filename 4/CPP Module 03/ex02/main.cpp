#include <iostream>

#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

int main() {
  std::cout << "* ClapTrap ACT" << std::endl;
  ClapTrap claptrap("Clappy");
  claptrap.attack("Enemy");
  claptrap.takeDamage(5);
  claptrap.beRepaired(5);
  std::cout << std::endl;

  std::cout << "* ScavTrap ACT" << std::endl;
  ScavTrap scavtrap("Scavvy");
  scavtrap.attack("Another Enemy");
  scavtrap.takeDamage(10);
  scavtrap.beRepaired(10);
  scavtrap.guardGate();
  std::cout << std::endl;

  std::cout << "* FragvTrap ACT" << std::endl;
  FragTrap fragtrap("Fraggy");
  fragtrap.attack("Yet Another Enemy");
  fragtrap.takeDamage(20);
  fragtrap.beRepaired(20);
  fragtrap.highFivesGuys();
  std::cout << std::endl;

  std::cout << "* Destructor" << std::endl;
  return 0;
}

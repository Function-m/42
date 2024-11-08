#include <iostream>

#include "ClapTrap.h"
#include "ScavTrap.h"

int main() {
  std::cout << "* Defalut Constructor" << std::endl;
  ClapTrap claptrap;
  ScavTrap scavtrap;
  std::cout << std::endl;

  std::cout << "* ClapTrap ACT" << std::endl;
  claptrap.attack("Enemy");
  claptrap.takeDamage(5);
  claptrap.beRepaired(5);
  std::cout << std::endl;

  std::cout << "* ScavTrap ACT" << std::endl;
  scavtrap.attack("Another Enemy");
  scavtrap.takeDamage(10);
  scavtrap.beRepaired(10);
  scavtrap.guardGate();
  std::cout << std::endl;

  std::cout << "* Destructor" << std::endl;
  return 0;
}

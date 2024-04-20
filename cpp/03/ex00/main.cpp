#include <iostream>

#include "ClapTrap.h"

int main() {
  std::cout << "* Defalut Constructor" << std::endl;
  ClapTrap ct01;
  std::cout << std::endl;

  std::cout << "* Default ACT" << std::endl;
  ct01.attack("Target Dummy");
  ct01.takeDamage(8);
  ct01.beRepaired(5);
  std::cout << std::endl;

  std::cout << "* No EP ACT" << std::endl;
  for (int i = 0; i < 10; ++i)
    ct01.attack("Target Dummy");
  ct01.beRepaired(1);
  ct01.takeDamage(3);
  std::cout << std::endl;

  std::cout << "* No HP ACT" << std::endl;
  ClapTrap ct02("Another CT");
  ct02.takeDamage(100);
  ct02.takeDamage(1000000000);
  ct02.beRepaired(1);
  ct02.attack("Target Dummy");
  std::cout << std::endl;

  std::cout << "* Copy Constructor" << std::endl;
  ClapTrap ct03 = ct01;
  std::cout << std::endl;

  std::cout << "* Copy Assignment Operator" << std::endl;
  ClapTrap yetCt02("Yet Another CT");
  yetCt02 = ct03;
  yetCt02.attack("Yet Another Target Dummy");
  std::cout << std::endl;

  std::cout << "* Destructor" << std::endl;
  return 0;
}

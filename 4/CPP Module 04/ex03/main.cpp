#include <iostream>

#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {
  const std::string AnsiRed("\033[0;31m");
  const std::string AnsiGreen("\033[0;32m");
  const std::string AnsiYellow("\033[1;33m");
  const std::string AnsiCyan("\033[0;36m");
  const std::string AnsiReset("\033[0m");

  std::cout << AnsiCyan << "\n-------- Materia Creation and Equipping --------" << AnsiReset << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp;

  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);

  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  // Over inventory size
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  std::cout << AnsiCyan << "\n-------- Using Equipped Materias on Bob --------" << AnsiReset << std::endl;
  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(3, *bob);

  // Attempt to use over inventory size
  me->use(4, *bob);

  std::cout << AnsiCyan << "\n-------- Unequip and Test Empty Slot --------" << AnsiReset << std::endl;
  me->unequip(2);
  me->use(2, *bob);

  delete bob;
  delete me;
  delete src;

  std::cout << std::endl;
  return 0;
}

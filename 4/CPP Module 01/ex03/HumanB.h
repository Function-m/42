#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <string>
#include <iostream>

#include "Weapon.h"

class HumanB {
 private:
  std::string name;
  Weapon* weapon;

 public:
  HumanB(std::string name);
  void setWeapon(Weapon& weapon);
  void attack() const;
};

#endif

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <string>

#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string name;

 public:
  DiamondTrap(std::string name = "DT");
  DiamondTrap(const DiamondTrap& src);
  ~DiamondTrap();

  DiamondTrap& operator=(const DiamondTrap& rhs);

  using ScavTrap::attack;
  void whoAmI();
};

#endif

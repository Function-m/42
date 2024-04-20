#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
 private:
  void printStatus();

 public:
  ScavTrap(std::string name = "ST");
  ScavTrap(const ScavTrap& src);
  virtual ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& rhs);

  void attack(const std::string& target);
  void guardGate();
};

#endif

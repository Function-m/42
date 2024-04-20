#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
 private:
  void printStatus();

 public:
  FragTrap(std::string name = "FT");
  FragTrap(const FragTrap& src);
  ~FragTrap();

  FragTrap& operator=(const FragTrap& rhs);

  void highFivesGuys(void);
};

#endif

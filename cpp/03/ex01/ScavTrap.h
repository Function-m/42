#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name = "ScavTrap");
    ScavTrap(const ScavTrap& src);
    virtual ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& rhs);

    void attack(const std::string& target);
    void guardGate();
};

#endif

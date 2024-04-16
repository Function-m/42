#include "ClapTrap.h"
#include "ScavTrap.h"
#include <iostream>

int main() {
    ClapTrap claptrap("Clappy");
    ScavTrap scavtrap("Scavvy");

    std::cout << "Testing ClapTrap:" << std::endl;
    claptrap.attack("Enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);

    std::cout << "\nTesting ScavTrap:" << std::endl;
    scavtrap.attack("Big Bad Enemy");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    return 0;
}

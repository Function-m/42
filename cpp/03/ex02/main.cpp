#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <iostream>

int main() {
    ClapTrap claptrap("Clappy");
    ScavTrap scavtrap("Scavvy");
    FragTrap fragtrap("Fraggy");

    std::cout << "Testing ClapTrap:" << std::endl;
    claptrap.attack("Enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);

    std::cout << "\nTesting ScavTrap:" << std::endl;
    scavtrap.attack("Big Bad Enemy");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    std::cout << "\nTesting FragTrap:" << std::endl;
    fragtrap.attack("Ultimate Enemy");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(20);
    fragtrap.highFivesGuys();

    return 0;
}

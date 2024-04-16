#include "ClapTrap.h"

int main() {
    ClapTrap claptrap("CT-01");

    std::cout << "Let the battles begin!" << std::endl;

    claptrap.attack("Target Dummy");
    claptrap.takeDamage(8);
    claptrap.beRepaired(5);

    // ClapTrap attempts to perform actions with insufficient resources
    std::cout << "Attempting more actions with insufficient resources:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        claptrap.attack("Another Target Dummy");
    }

    claptrap.takeDamage(3);
    claptrap.beRepaired(1);

    // A new ClapTrap to demonstrate copy construction and assignment
    ClapTrap anotherClaptrap = claptrap;
    ClapTrap yetAnotherClaptrap("CT-02");
    yetAnotherClaptrap = anotherClaptrap;

    yetAnotherClaptrap.attack("Yet Another Target Dummy");

    return 0;
}

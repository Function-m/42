#include "DiamondTrap.h"

int main() {
    DiamondTrap diamond("DiamondHero");

    diamond.whoAmI();
    diamond.attack("Evil Villain");
    diamond.takeDamage(15);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.highFivesGuys();

    return 0;
}

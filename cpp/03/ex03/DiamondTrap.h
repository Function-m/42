#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;

public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& src);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& rhs);

    using ScavTrap::attack;
    void whoAmI();

    // 추가적으로 필요한 함수가 있다면 여기에 선언
};

#endif

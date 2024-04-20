#include <iostream>

#include "DiamondTrap.h"

int main() {
  std::cout << "* DiamondTrap ACT" << std::endl;
  DiamondTrap diamond("DT");

  // DiamondTrap의 고유 기능
  std::cout << "\n* Testing DiamondTrap specific functionalities" << std::endl;
  diamond.whoAmI();

  // 공격 메쏘드 테스트
  std::cout << "\n* Testing attack functionality" << std::endl;
  diamond.attack("Dummy");  // ScavTrap의 attack을 사용

  // 데미지 받는 기능 테스트
  std::cout << "\n* Testing damage functionality" << std::endl;
  diamond.takeDamage(15);  // ClapTrap의 takeDamage를 사용

  // 수리 기능 테스트
  std::cout << "\n* Testing repair functionality" << std::endl;
  diamond.beRepaired(20);  // ClapTrap의 beRepaired를 사용

  // ScavTrap의 guardGate 기능 테스트
  std::cout << "\n* Testing ScavTrap's guardGate functionality" << std::endl;
  diamond.guardGate();

  // FragTrap의 highFivesGuys 기능 테스트
  std::cout << "\n* Testing FragTrap's highFivesGuys functionality" << std::endl;
  diamond.highFivesGuys();

  std::cout << "\n* Destructor\n";
  return 0;
}

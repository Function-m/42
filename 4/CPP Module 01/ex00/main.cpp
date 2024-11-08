#include <iomanip>
#include "Zombie.h"

Zombie *testZombieMemoryAllocation() {
  Zombie *heapMemoryZombie = newZombie("heapMemoryZombie");
  return (heapMemoryZombie);
}

int main() {
  Zombie *heapMemoryZombie = testZombieMemoryAllocation();
  std::cout << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << std::endl;

  randomChump("stackMemoryZombie");
  std::cout << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << std::endl;

  heapMemoryZombie->announce();
  delete heapMemoryZombie;
  return 0;
}

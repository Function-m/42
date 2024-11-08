#include <iomanip>
#include "Zombie.h"

int main() {
  int N = 5;
  Zombie* horde = zombieHorde(N, "HordeZombie");

  for (int i = 0; i < N; i++) {
    horde[i].announce();
  }
  std::cout << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << std::endl;
  delete[] horde;
  return 0;
}

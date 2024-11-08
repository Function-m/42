#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name) {
  announce();
}

Zombie::~Zombie() {
  std::cout << name << " was destroyed." << std::endl;
}

void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
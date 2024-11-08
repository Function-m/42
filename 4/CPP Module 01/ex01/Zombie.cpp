#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name) {
  announce();
}

Zombie::~Zombie() {
  std::cout << name << " was destroyed." << std::endl;
}

void Zombie::announce(void) const {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  this->name = name;
}

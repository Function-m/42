#include "Zombie.h"

Zombie* newZombie(std::string name) {
  try {
    return new Zombie(name);

  } catch (const std::bad_alloc& e) {
    std::cout << "Memory allocation failed: " << e.what() << std::endl;
    return nullptr;

  } catch (const std::exception& e) {
    std::cout << "Zombie object creation failed: " << e.what() << std::endl;
    return nullptr;
  }
}

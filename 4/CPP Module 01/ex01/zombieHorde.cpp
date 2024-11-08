#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
  Zombie* horde = nullptr;
  try {
    horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
      horde[i].setName(name);
    }
    return horde;

  } catch (const std::bad_alloc& e) {
    std::cout << "Memory allocation failed: " << e.what() << '\n';
    return nullptr;

  } catch (const std::exception& e) {
    std::cout << "An exception occurred: " << e.what() << '\n';
    delete[] horde;
    return nullptr;
  }
}

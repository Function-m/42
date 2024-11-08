#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
 public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce(void) const;
  void setName(std::string name);

 private:
  std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif

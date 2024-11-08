#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter {
 private:
  std::string name;
  static const int INVENTORY_SIZE = 4;
  AMateria* inventory[INVENTORY_SIZE];

 public:
  Character(std::string name = "AAAAA");
  Character(const Character& src);
  ~Character();

  Character& operator=(const Character& rhs);

  std::string const& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
};

#endif

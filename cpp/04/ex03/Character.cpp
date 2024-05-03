#include "Character.h"

Character::Character(std::string name) : name(name) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    this->inventory[i] = NULL;
  }
}

Character::Character(const Character& src) : name(src.name) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    if (src.inventory[i])
      this->inventory[i] = src.inventory[i];
    else
      this->inventory[i] = NULL;
  }
}

Character::~Character() {
}

Character& Character::operator=(const Character& rhs) {
  if (this != &rhs) {
    this->name = rhs.name;
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
      if (rhs.inventory[i])
        this->inventory[i] = rhs.inventory[i];
      else
        this->inventory[i] = NULL;
    }
  }
  return *this;
}

std::string const& Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < INVENTORY_SIZE; ++i) {
    if (!this->inventory[i]) {
      this->inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < INVENTORY_SIZE && this->inventory[idx] != NULL)
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < INVENTORY_SIZE && this->inventory[idx] != NULL)
    this->inventory[idx]->use(target);
}

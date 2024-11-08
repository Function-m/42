#include "AMateria.h"

#include <iostream>

#include "ICharacter.h"

AMateria::AMateria(std::string const &type) : type(type) {
}

AMateria::AMateria() {}
AMateria::AMateria(const AMateria &src) : type(src.type) {}
AMateria::~AMateria() {}
AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this != &rhs)
    type = rhs.type;
  return *this;
}

std::string const &AMateria::getType() const { return type; }
void AMateria::use(ICharacter& target) {
  std::cout << "AMateria::use called on " << target.getName() << " with no effect." << std::endl;
}
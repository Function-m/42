#ifndef CURE_H
#define CURE_H

#include "AMateria.h"
#include "ICharacter.h"

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure& src);
  ~Cure();

  Cure& operator=(const Cure& rhs);

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif

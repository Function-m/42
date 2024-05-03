#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

#include "ICharacter.h"

class ICharacter;

class AMateria {
 protected:
  // ↓ The Added Part ↓
  std::string type;
  // ↑ The Added Part ↑

 public:
  AMateria(std::string const& type);

  // ↓ The Added Part ↓
  AMateria();
  AMateria(const AMateria& src);
  virtual ~AMateria();
  AMateria& operator=(const AMateria& rhs);
  // ↑ The Added Part ↑

  std::string const& getType() const;

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif

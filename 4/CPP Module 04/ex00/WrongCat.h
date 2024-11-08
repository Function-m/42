#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& src);
  ~WrongCat();

  WrongCat& operator=(const WrongCat& rhs);

  void makeSound() const;
};

#endif

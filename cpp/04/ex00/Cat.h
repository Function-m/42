#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& src);
  ~Cat();

  Cat& operator=(const Cat& rhs);

  virtual void makeSound() const;
};

#endif

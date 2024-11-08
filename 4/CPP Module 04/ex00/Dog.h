#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& src);
  ~Dog();

  Dog& operator=(const Dog& rhs);

  virtual void makeSound() const;
};

#endif

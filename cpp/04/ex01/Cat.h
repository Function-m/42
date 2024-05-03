#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  Cat();
  Cat(const Cat& src);
  ~Cat();

  Cat& operator=(const Cat& rhs);

  void makeSound() const;
};

#endif

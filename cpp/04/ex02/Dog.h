#ifndef DOG_H
#define DOG_H

#include "AAnimal.h"

class Dog : public AAnimal {
public:
    Dog();
    Dog(const Dog& src);
    virtual ~Dog();

    Dog& operator=(const Dog& rhs);

    void makeSound() const;
};

#endif

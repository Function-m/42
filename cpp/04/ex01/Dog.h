#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& src);
    virtual ~Dog();

    Dog& operator=(const Dog& rhs);

    virtual void makeSound() const;
};

#endif

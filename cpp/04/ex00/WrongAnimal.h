#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);
    virtual ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& rhs);

    void makeSound() const;
    std::string getType() const;
};

#endif

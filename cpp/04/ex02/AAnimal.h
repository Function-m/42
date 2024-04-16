#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& src);
    virtual ~AAnimal();

    AAnimal& operator=(const AAnimal& rhs);

    virtual void makeSound() const = 0; // 순수 가상 함수
    std::string getType() const;
};

#endif

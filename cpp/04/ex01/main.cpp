#include "Dog.h"
#include "Cat.h"

int main() {
    const Animal* animals[4];

    for (int i = 0; i < 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    // Deep copy test
    Dog originalDog;
    Dog copyDog(originalDog);
    Cat originalCat;
    Cat copyCat(originalCat);

    return 0;
}

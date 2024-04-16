#include "Dog.h"
#include "Cat.h"

int main() {
    // AAnimal* meta = new AAnimal(); // 이제 컴파일되지 않음
    AAnimal* j = new Dog();
    AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    return 0;
}

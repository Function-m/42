#include "Cat.h"
#include "Dog.h"

int main() {
  // Animal* meta = new Animal(); // Compile Error
  Animal* j = new Dog();
  Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();

  delete j;
  delete i;

  return 0;
}

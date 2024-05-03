#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

int main() {
  const std::string AnsiRed("\033[0;31m");
  const std::string AnsiGreen("\033[0;32m");
  const std::string AnsiYellow("\033[1;33m");
  const std::string AnsiCyan("\033[0;36m");
  const std::string AnsiReset("\033[0m");

  std::cout << AnsiCyan << "-------- Correct Implementation Test --------" << AnsiReset << std::endl;

  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << AnsiGreen << "Animal's Type: " << AnsiReset << meta->getType() << " " << std::endl;
  std::cout << AnsiGreen << "Dog's Type: " << AnsiReset << j->getType() << " " << std::endl;
  std::cout << AnsiGreen << "Cat's Type: "  << AnsiReset << i->getType() << " " << std::endl;

  std::cout << AnsiYellow << "Animal makes sound: " << AnsiReset;
  meta->makeSound();
  std::cout << AnsiYellow << "Dog makes sound: " << AnsiReset;
  j->makeSound();
  std::cout << AnsiYellow << "Cat makes sound: " << AnsiReset;
  i->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << AnsiRed << "\n-------- Incorrect Implementation Test --------" << AnsiReset << std::endl;

  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << AnsiGreen << "WrongAnimal's Type: " << AnsiReset << meta->getType() << " " << std::endl;
  std::cout << AnsiGreen << "WrongCat's Type: " << AnsiReset << wrongCat->getType()  << " " << std::endl;

  std::cout << AnsiYellow << "WrongAnimal makes sound: " << AnsiReset;
  wrongMeta->makeSound();
  std::cout << AnsiYellow << "WrongCat makes sound: " << AnsiReset;
  wrongCat->makeSound();

  delete wrongMeta;
  delete wrongCat;

  std::cout << std::endl;
  return 0;
}

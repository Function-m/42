#include <iostream>

#include "Cat.h"
#include "Dog.h"

int main() {
  const std::string AnsiRed("\033[0;31m");
  const std::string AnsiGreen("\033[0;32m");
  const std::string AnsiYellow("\033[1;33m");
  const std::string AnsiCyan("\033[0;36m");
  const std::string AnsiReset("\033[0m");

  std::cout << AnsiCyan << "\n-------- Dynamic Allocation and Deallocation Test --------" << AnsiReset << std::endl;

  const Animal *animals[4];

  for (int i = 0; i < 2; ++i) {
    std::cout << AnsiGreen << "Creating Dog " << i + 1 << "." << AnsiReset << std::endl;
    animals[i] = new Dog();
  }

  for (int i = 2; i < 4; ++i) {
    std::cout << AnsiGreen << "Creating Cat " << i - 1 << "." << AnsiReset << std::endl;
    animals[i] = new Cat();
  }

  for (int i = 0; i < 4; ++i) {
    std::cout << AnsiRed << "Deleting Animal " << i + 1 << "." << AnsiReset << std::endl;
    delete animals[i];
  }

  std::cout << AnsiCyan << "\n-------- Deep Copy Test --------" << AnsiReset << std::endl;

  std::cout << AnsiYellow << "Creating original Dog and initiating copy." << AnsiReset << std::endl;
  Dog *originalDog = new Dog();
  Dog *copyDog = new Dog(*originalDog);

  std::cout << AnsiGreen << "Deleting original Dog." << AnsiReset << std::endl;
  delete originalDog;

  std::cout << AnsiGreen << "Deleting copy Dog after making sound." << AnsiReset << std::endl;
  copyDog->makeSound();
  delete copyDog;

  std::cout << AnsiYellow << "Creating original Cat and initiating copy." << AnsiReset << std::endl;
  Cat *originalCat = new Cat();
  Cat *copyCat = new Cat(*originalCat);

  std::cout << AnsiGreen << "Deleting original Cat." << AnsiReset << std::endl;
  delete originalCat;

  std::cout << AnsiGreen << "Deleting copy Cat after making sound." << AnsiReset << std::endl;
  copyCat->makeSound();
  delete copyCat;

  std::cout << AnsiYellow << "Creating another Dog for assignment." << AnsiReset << std::endl;
  Dog *anotherDog = new Dog();
  Dog *assignedDog = new Dog();

  std::cout << AnsiYellow << "Assigning and deleting another Dog." << AnsiReset << std::endl;
  *assignedDog = *anotherDog;
  delete anotherDog;

  std::cout << AnsiGreen << "Deleting assigned Dog after making sound." << AnsiReset << std::endl;
  assignedDog->makeSound();
  delete assignedDog;

  std::cout << AnsiYellow << "Creating another Cat for assignment." << AnsiReset << std::endl;
  Cat *anotherCat = new Cat();
  Cat *assignedCat = new Cat();

  std::cout << AnsiYellow << "Assigning and deleting another Cat." << AnsiReset << std::endl;
  *assignedCat = *anotherCat;
  delete anotherCat;

  std::cout << AnsiGreen << "Deleting assigned Cat after making sound." << AnsiReset << std::endl;
  assignedCat->makeSound();
  delete assignedCat;

  std::cout << std::endl;
  return 0;
}

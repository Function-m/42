#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate() {
  srand(time(0));
  int choice = rand() % 3;
  switch (choice) {
    case 0:
      return new A;
    case 1:
      return new B;
    case 2:
      return new C;
  }
  return 0;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "A\n";
  else if (dynamic_cast<B*>(p) != NULL)
    std::cout << "B\n";
  else if (dynamic_cast<C*>(p) != NULL)
    std::cout << "C\n";
}

void identify(Base& p) {
  Base* temp;

  try {
    A& a = dynamic_cast<A&>(p);;
    temp = &a;
    std::cout << "A\n";
    return;
  } catch (const std::bad_cast&) {
  }

  try {
    B& b = dynamic_cast<B&>(p);
    temp = &b;
    std::cout << "B\n";
    return;
  } catch (const std::bad_cast&) {
  }

  try {
    C& c = dynamic_cast<C&>(p);
    temp = &c;
    std::cout << "C\n";
    return;
  } catch (const std::bad_cast&) {
  }
  std::cout << "Unknown type\n";
}

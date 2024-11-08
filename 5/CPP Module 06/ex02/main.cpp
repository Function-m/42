#include "Base.hpp"
#include <iostream>

int main() {
  std::cout << "Random class\n";
  Base* base = generate();
  identify(base);
  identify(*base);
  delete base;

  std::cout << "\nA class\n";
  A a;
  identify(&a);
  identify(a);

  std::cout << "\nB class\n";
  B b;
  identify(&b);
  identify(b);

  std::cout << "\nC class\n";
  C c;
  identify(&c);
  identify(c);
  return 0;
}

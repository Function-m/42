#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR = &str;
  std::string& stringREF = str;

  const int width = 42;
  std::cout << std::left
            << std::setw(width) << "The memory address of the string variable" << ": " << &str << "\n"
            << std::setw(width) << "The memory address held by stringPTR" << ": " << stringPTR << "\n"
            << std::setw(width) << "The memory address held by stringREF" << ": " << &stringREF << "\n"

            << std::setfill('-') << std::setw(width + 20) << "" << std::setfill(' ') << "\n"

            << std::setw(width) << "The value of the string variable" << ": " << str << "\n"
            << std::setw(width) << "The value pointed to by stringPTR" << ": " << *stringPTR << "\n"
            << std::setw(width) << "The value pointed to by stringREF" << ": "  << stringREF << std::endl;

  return 0;
}

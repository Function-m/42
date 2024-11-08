#include <cctype>
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* OUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; ++i) {
      for (size_t j = 0; j < std::strlen(argv[i]); j++) {
        argv[i][j] = static_cast<char>(std::toupper(argv[i][j]));
      }
      std::cout << argv[i];
    }
  }
  std::cout << std::endl;
  return 0;
}

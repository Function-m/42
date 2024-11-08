#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2 || !argv[1] || !argv[1][0]) {
    std::cerr << "Usage: ./convert <literal-to-convert>" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}
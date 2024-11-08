#include "FileReplacer.h"

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
  }

  try {
    FileReplacer replace(argv[1], argv[2], argv[3]);

  } catch (const std::runtime_error& e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
    return 1;

  } catch (const std::exception& e) {
    std::cout << "Standard exception: " << e.what() << std::endl;
    return 1;

  } catch (...) {
    std::cout << "An unknown error occurred." << std::endl;
    return 1;
  }
  return 0;
}

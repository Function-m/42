#include "PmergeMe.hpp"

// https://en.wikipedia.org/wiki/Merge-insertion_sort

int main(int argc, char* argv[]) {
  try {
    PmergeMe pmergeMe(argc, argv);

    pmergeMe.sortAndCountTime();
    pmergeMe.displayAll();
    
    return 0;
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
    return 1;
  }
}

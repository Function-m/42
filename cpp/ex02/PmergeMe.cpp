#include "PmergeMe.hpp"

// For Orthodox Canonical Form
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {
  vec = other.vec;
  lst = other.lst;
  vecTime = other.vecTime;
  lstTime = other.lstTime;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    vec = other.vec;
    lst = other.lst;
    vecTime = other.vecTime;
    lstTime = other.lstTime;
  }
  return *this;
}

PmergeMe::PmergeMe(int argc, char* argv[]): mainArgc(argc), mainArgv(argv) {
  if (mainArgc < 2) {
    throw std::invalid_argument("No input provided.");
    return;
  }

  int num;
  for (int i = 1; i < mainArgc; ++i) {
    std::istringstream iss(mainArgv[i]);
    if (!(iss >> num && iss.eof()) || num < 0) {
      throw std::invalid_argument("Invalid number or negative number not allowed.");
    }
    for (size_t i = 0; i < vec.size(); ++i) {
      if (vec[i] == num) {
        throw std::invalid_argument("Duplicate number not allowed.");
      }
    }
    vec.push_back(num);
    lst.push_back(num);
  }
}

void PmergeMe::sortAndCountTime() {
  clock_t start, end;

  if (vec.size() == 1) {
    return;
  }

  start = clock();
  sortVector(vec);
  end = clock();
  vecTime = double(end - start) / CLOCKS_PER_SEC * 1000000;  // microseconds

  start = clock();
  sortList(lst);
  end = clock();
  lstTime = double(end - start) / CLOCKS_PER_SEC * 1000000;  // microseconds
}

void PmergeMe::displayAll() {
  std::cout << "Before:";
  for (int i = 1; i < mainArgc; ++i) {
    std::cout << " " << mainArgv[i];
  }
  std::cout << "\n";

  std::cout << "std::vector After:";
  for (unsigned int i = 0; i < vec.size(); ++i) {
    std::cout << " " << vec[i];
  }
  std::cout << " | "
            << "std::list After:";
  for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << "\n";

  std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime << " us" << std::endl;
  std::cout << "Time to process a range of " << lst.size() << " elements with std::list:   " << lstTime << " us" << std::endl;
}

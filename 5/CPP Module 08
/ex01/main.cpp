#include <iostream>
#include <vector>

#include "Span.h"

int main() {
  Span sp = Span(5);
  std::cout << "\n* addNumber\n";
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << "\n* shortestSpan\n";
  std::cout << sp.shortestSpan() << std::endl;

  std::cout << "\n* longestSpan\n";
  std::cout << sp.longestSpan() << std::endl;

  std::cout << "\n* addNumber with iterator\n";
  std::vector<int> moreNumbers;
  for (int i = 1; i <= 10000; i++) {
    moreNumbers.push_back(i);
  }
  Span bigSpan(10005);
  bigSpan.addNumber(moreNumbers.begin(), moreNumbers.end());

  bigSpan.addNumber(1);
  bigSpan.addNumber(2);
  bigSpan.addNumber(3);
  bigSpan.addNumber(4);
  bigSpan.addNumber(5);

  std::cout << bigSpan.shortestSpan() << std::endl;
  std::cout << bigSpan.longestSpan() << std::endl;

  Span temp(3);
  int arr[] = {1, 2, 3};
  temp.addNumber(&arr[0], &arr[3]);

  return 0;
}

#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
 public:
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();
  Span &operator=(const Span &other);

  template <typename Iterator>
  void addNumber(Iterator begin, Iterator end);
  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;

 private:
  Span();
  unsigned int maxSize;
  std::vector<int> integers;
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
  if (std::distance(begin, end) > static_cast<int>(maxSize - integers.size())) {
    throw std::out_of_range("Not enough space to add all integers");
  }
  integers.insert(integers.end(), begin, end);
}

#endif

#include "Span.h"

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span &other) : maxSize(other.maxSize), integers(other.integers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    maxSize = other.maxSize;
    integers = other.integers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (integers.size() >= maxSize) {
    throw std::out_of_range("Span is already full");
  }
  integers.push_back(number);
}

int Span::shortestSpan() const {
  if (integers.size() < 2) {
    throw std::logic_error("Not enough integers to find a Span");
  }
  std::vector<int> sorted = integers;
  std::sort(sorted.begin(), sorted.end());
  int minSpan = sorted[1] - sorted[0];
  for (std::size_t i = 1; i < sorted.size() - 1; ++i) {
    int span = sorted[i + 1] - sorted[i];
    if (span < minSpan) {
      minSpan = span;
    }
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (integers.size() < 2) {
    throw std::logic_error("Not enough integers to find a Span");
  }
  std::vector<int>::const_iterator minIt = std::min_element(integers.begin(), integers.end());
  std::vector<int>::const_iterator maxIt = std::max_element(integers.begin(), integers.end());
  return *maxIt - *minIt;
}

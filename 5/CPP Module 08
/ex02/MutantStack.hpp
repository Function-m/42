#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() : std::stack<T>() {}
  MutantStack(const MutantStack &other) : std::stack<T>(other) {}
  virtual ~MutantStack() {}
  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }

  // container_type는 실제 stack의 기반이 되는 contianer의 타입을 나타냅니다.
  typedef typename std::stack<T>::container_type::iterator iterator;

  iterator begin() {
    return this->c.begin();
  }

  iterator end() {
    return this->c.end();
  }
};

#endif

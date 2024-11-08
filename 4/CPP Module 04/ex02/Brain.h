#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
 private:
 static const int IDEAS_SIZE = 100;
  std::string ideas[IDEAS_SIZE];

 public:
  Brain();
  Brain(const Brain& src);
  ~Brain();

  Brain& operator=(const Brain& rhs);
};

#endif

#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
public:
    std::string ideas[100];

    Brain();
    Brain(const Brain& src);
    ~Brain();

    Brain& operator=(const Brain& rhs);
};

#endif

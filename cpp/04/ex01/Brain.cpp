#include "Brain.h"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain& src) {
    *this = src;
    std::cout << "Brain copied." << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destroyed." << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

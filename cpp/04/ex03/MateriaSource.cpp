#include "MateriaSource.h"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        this->templates[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& src) {
    for (int i = 0; i < 4; ++i) {
        if (src.templates[i])
            this->templates[i] = src.templates[i]->clone();
        else
            this->templates[i] = nullptr;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete this->templates[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; ++i) {
            delete this->templates[i];
            if (rhs.templates[i])
                this->templates[i] = rhs.templates[i]->clone();
            else
                this->templates[i] = nullptr;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!this->templates[i]) {
            this->templates[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (this->templates[i] && this->templates[i]->getType() == type) {
            return this->templates[i]->clone();
        }
    }
    return nullptr;
}


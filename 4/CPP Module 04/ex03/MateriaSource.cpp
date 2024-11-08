#include "MateriaSource.h"

#include "AMateria.h"

MateriaSource::MateriaSource() {
  for (int i = 0; i < TEMPLATES_SIZE; ++i)
    this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
  for (int i = 0; i < TEMPLATES_SIZE; ++i) {
    if (src.templates[i] != NULL)
      this->templates[i] = src.templates[i]->clone();
    else
      this->templates[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < TEMPLATES_SIZE; ++i)
    delete this->templates[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
  if (this != &rhs) {
    for (int i = 0; i < TEMPLATES_SIZE; ++i) {
      if (rhs.templates[i] != NULL) {
        delete this->templates[i];
        this->templates[i] = rhs.templates[i]->clone();
      }
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < TEMPLATES_SIZE; ++i) {
    if (!this->templates[i]) {
      this->templates[i] = m;
      return;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < TEMPLATES_SIZE; ++i) {
    if (this->templates[i] && this->templates[i]->getType() == type)
      return this->templates[i]->clone();
  }
  return NULL;
}

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
 private:
  static const int TEMPLATES_SIZE = 4;
  AMateria* templates[TEMPLATES_SIZE];

 public:
  MateriaSource();
  MateriaSource(const MateriaSource& src);
  ~MateriaSource();

  MateriaSource& operator=(const MateriaSource& rhs);

  void learnMateria(AMateria*);
  AMateria* createMateria(std::string const& type);
};

#endif

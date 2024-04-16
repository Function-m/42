#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    virtual ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& rhs);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif

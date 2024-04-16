#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& src);
    ~Ice();

    Ice& operator=(const Ice& rhs);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif

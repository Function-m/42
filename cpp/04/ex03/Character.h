#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character(std::string name = "default");
    Character(const Character& src);
    virtual ~Character();

    Character& operator=(const Character& rhs);

    std::string const & getName() const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;
};

#endif

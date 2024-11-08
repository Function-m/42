#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
 public:
  Weapon(std::string type);
  const std::string& getType() const;
  void setType(const std::string& type);

 private:
  std::string type;
};

#endif

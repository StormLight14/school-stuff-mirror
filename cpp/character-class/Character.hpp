#pragma once
#include <iostream>
#include <sstream>

using std::ostream, std::string;

class Character {
  public:
    Character(int health, int damage, int defense): health(health), damage(damage), defense(defense) {}
    friend ostream& operator<<(ostream& out, const Character& self);
    virtual string toString() const;
  protected:
    int health;
    int damage;
    int defense;
};

string Character::toString() const {
  std::stringstream ss;
  ss << "Health: " << health << "\nDamage: " << damage << "\nDefense: " << defense << std::endl;
  return ss.str();
}

ostream& operator<<(ostream& out, const Character& self) {
  out << self.toString();
  return out;
}

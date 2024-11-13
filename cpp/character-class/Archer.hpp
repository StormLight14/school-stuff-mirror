#pragma once
#include "Character.hpp"
#include <sstream>

class Archer: public Character {
  public:
    Archer(int health, int damage, int defense, int arrows): Character(health, damage, defense), arrows(arrows) {}
    friend ostream& operator<<(ostream& out, const Archer& self);
    string toString() const;
  private:
    int arrows;
};

string Archer::toString() const {
  std::stringstream ss;
  ss << Character::toString();
  ss << "Arrows: " << arrows;
  return ss.str();
}

ostream& operator<<(ostream& out, const Archer& self) {
  out << self.toString();
  return out;
}

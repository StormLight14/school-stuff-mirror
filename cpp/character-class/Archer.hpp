#pragma once
#include "Character.hpp"
#include <sstream>

class Archer: public Character {
  public:
    Archer(int health, int damage, int defense, int arrows): Character(health, damage, defense), arrows(arrows) {}
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

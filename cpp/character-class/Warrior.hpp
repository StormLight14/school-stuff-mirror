#pragma once
#include "Character.hpp"
#include <sstream>

class Warrior: public Character {
  public:
    Warrior(int health, int damage, int defense, std::string sword): Character(health, damage, defense), sword(sword) {}
    friend ostream& operator<<(ostream& out, const Warrior& self);
    string toString() const;
  private:
    std::string sword;
};

string Warrior::toString() const {
  std::stringstream ss;
  ss << Character::toString();
  ss << "Sword: " << sword;
  return ss.str();
}

ostream& operator<<(ostream& out, const Warrior& self) {
  out << self.toString();
  return out;
}

#pragma once
#include "Character.hpp"
#include <sstream>

class Mage: public Character {
  public:
    Mage(int health, int damage, int defense, int mana): Character(health, damage, defense), mana(mana) {}
    friend ostream& operator<<(ostream& out, const Mage& self);
    string toString() const;
  private:
    int mana;
};

string Mage::toString() const {
  std::stringstream ss;
  ss << Character::toString();
  ss << "Mana: " << mana;
  return ss.str();
}

ostream& operator<<(ostream& out, const Mage& self) {
  out << self.toString();
  return out;
}

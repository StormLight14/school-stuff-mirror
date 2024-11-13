#pragma once
#include "Character.hpp"
#include <sstream>

class Mage: public Character {
  public:
    Mage(int health, int damage, int defense, int mana): Character(health, damage, defense), mana(mana) {}
     virtual string toString() const override;
  private:
    int mana;
};

string Mage::toString() const {
  std::stringstream ss;
  ss << Character::toString();
  ss << "Mana: " << mana;
  return ss.str();
}

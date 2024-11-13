#pragma once
#include "Character.hpp"
#include <sstream>

class Warrior: public Character {
  public:
    Warrior(int health, int damage, int defense, std::string sword): Character(health, damage, defense), sword(sword) {}
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

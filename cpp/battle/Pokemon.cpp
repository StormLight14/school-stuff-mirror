#include "Pokemon.h"
#include <random>

using std::string;

Pokemon::Pokemon() {
  name = "Eevee";
  hp = 100;
  strength = 0;
}

Pokemon::Pokemon(string name) {
  this->name = name;
  hp = 100;
  strength = 0;
}

int Pokemon::getStrength() {
  return strength;
}

void Pokemon::setRandomStrength() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(10 , 40);
  strength = dist(gen);
}

int Pokemon::getHp() {
  return hp;
}

void Pokemon::takeDamage(int damage) {
  hp -= damage;
}

string Pokemon::getName() {
  return name;
}

void Pokemon::battle(Pokemon opponent) {
  setRandomStrength();
  opponent.setRandomStrength();

  if (strength >= opponent.getStrength()) {
    opponent.takeDamage(strength - opponent.getStrength());
  } else {
    takeDamage(opponent.getStrength() - strength);
  }
}

ostream& operator<<(ostream &out, Pokemon pokemon) {
  out << std::setw(10) << pokemon.name << ": " << setw(12);

  for (int i = 0; i < 100; i += 10) {
    if (i <= pokemon.hp) {
      out << "@";
    } else {
      out << "*";
    }
  }

  return out;
}

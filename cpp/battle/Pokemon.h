#pragma once

#include <iostream>
#include <ostream>
#include <iomanip>

using std::string, std::ostream, std::setw;

class Pokemon {
  public:
    Pokemon();
    Pokemon(string);
    void battle(Pokemon);
    void setRandomStrength();
    int getStrength();
    string getName();
    int getHp();
    void takeDamage(int);
    friend ostream& operator<<(ostream &, Pokemon);

  private:
    string name;
    int hp;
    int strength;
};

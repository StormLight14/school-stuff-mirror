#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Mage.hpp"
#include "Archer.hpp"
#include "Warrior.hpp"

using std::cout, std::endl, std::vector;

int main() {
  vector<Character*> charList;
  charList.push_back(new Mage(100, 30, 10, 100));
  charList.push_back(new Archer(150, 15, 15, 64));
  charList.push_back(new Warrior(200, 20, 20, "Excalibur"));
  charList.push_back(new Character(1, 1, 1));

  for (auto c : charList) {
    cout << *c << "\n" << endl;
  }

  for (auto c : charList) {
    delete c;
  }

  return 0;
}

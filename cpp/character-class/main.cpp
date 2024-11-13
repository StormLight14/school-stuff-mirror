#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Mage.hpp"
#include "Archer.hpp"
#include "Warrior.hpp"

using std::cout, std::endl, std::vector;

int main() {
  vector<Character> charList;
  charList.push_back(Mage(100, 30, 10, 100));
  charList.push_back(Archer(150, 15, 15, 64));
  charList.push_back(Warrior(200, 20, 20, "Excalibur"));
  charList.push_back(Character(1, 1, 1));

  for (const Character& c : charList) {
    cout << c << endl;
  }

  return 0;
}

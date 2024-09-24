#include <iostream>
#include "Pokemon.h"

using std::cout, std::cin, std::endl;

int main() {
  cout << "Pokemon Battle!" << endl;

  string name;
  cout << "Enter the name of your Pokemon: ";
  cin >> name;

  Pokemon you(name);
  Pokemon computer;

  while (true) {
    cout << you << endl;
    cout << computer << endl;

    string choice;
    cout << "(b)attle or (quit): ";
    cin >> choice;

    if (choice == "q") {
      break;
    }

    if (you.getHp() > 0) {
      cout << "You win!";
    } else {
      cout << "You lose.";
    }

    you.battle(computer);
  }

  return 0;
}

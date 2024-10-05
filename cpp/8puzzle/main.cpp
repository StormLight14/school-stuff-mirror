#include "Game.h"
#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  Game game;
  cout << "8 Puzzle!" << endl;
  
  bool playing = true;
  while (playing) {
    cout << game;
    cout << "Choose a number to move: ";
    int choice;
    cin >> choice;
  }
  return 0;
}

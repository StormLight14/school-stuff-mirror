#include "Game.h"
#include <cstdlib>
#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  Game game;
  cout << "8 Puzzle!" << endl;
  
  while (game.hasWon() == false) {
    cout << game;
    cout << "Choose a number to move: ";
    int choice;
    cin >> choice;
    game.movePiece(choice);
  }

  cout << "You Won!" << endl;

  return 0;
}

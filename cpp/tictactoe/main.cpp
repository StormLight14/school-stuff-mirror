#include <iostream>
#include "TTTGrid.h"

using std::cin, std::cout, std::endl, std::system;

int main() {
  TTTGrid game;
  char choice;

  while (true) {
    system("clear");
    cout << "TicTacToe!" << endl;
    cout << game;
    cout << endl << game.getCurrentPlayer() << "'s turn: ";
    cin >> choice;

    game.selectMove(choice);
    if (game.hasWon()) {
      system("clear");
      cout << game;
      cout << game.getCurrentPlayer() << " Wins!";
      break;
    } else {
      game.switchPlayer();
    }
  }

  return 0;
}

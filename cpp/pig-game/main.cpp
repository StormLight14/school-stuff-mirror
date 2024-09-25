#include <iomanip>
#include <iostream>
#include <string>
#include "PigPlayer.h"

using std::cout, std::cin, std::setw, std::endl, std::string;

void printTotals(PigPlayer, PigPlayer);
void computerTurn(PigPlayer &);
void playerTurn(PigPlayer &);

int main() {
  bool playing = true;
  PigPlayer computer;
  PigPlayer player;

  while (playing) {
    printTotals(computer, player);
    // player turn
    if (playing == true) {
      playerTurn(player);
    }

    if (player.getTotal() >= 100) {
      cout << "PLAYER WON!" << endl;
      playing = false;
    }

    // computer turn
    if (playing == true) {
      computerTurn(computer);
    }

    if (computer.getTotal() >= 100) {
      cout << "COMPUTER WON!" << endl;
      playing = false;
    }
  }

  return 0;
}

void computerTurn(PigPlayer &computer) {
  computer.isTurn = true;
  while (computer.isTurn) {
    computer.roll();
    string choice = computer.pickOption();
    if (choice == "roll") {
      computer.roll();
    } else if (choice == "stop") {
      computer.stop();
    } else {
      cout << "COMPUTER MADE INVALID CHOICE: " << choice << endl;
    }
  }
}

void playerTurn(PigPlayer &player) {
  player.isTurn = true;
  while (player.isTurn) {
    cout << "(1) Roll, (2) Stop: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
      player.roll();
      cout << setw(10) << "Your Turn Total: " << player.getTurnTotal() << "\n" << endl;
    } else if (choice == 2) {
      player.stop();
    } else {
      cout << "Invalid Input." << endl;
      continue;
    }
  }

}

void printTotals(PigPlayer computer, PigPlayer player) {
  cout << setw(10) << "Your Total: " << player.getTotal() << endl;
  cout << setw(10) << "Computer Total: " << computer.getTotal() << endl;
}

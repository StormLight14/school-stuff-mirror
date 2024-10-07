#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::endl, std::cout;

Game::Game() {
    int alreadySelected[9] = {0}; // Array to track selected numbers, initialized to 0

    srand(time(0)); // Initialize random seed

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        int num = rand() % 9 + 1; // Generate a random number between 1 and 9

        // Check if the number has already been selected
        while (alreadySelected[num - 1] != 0) {
          num = rand() % 9 + 1; // Keep generating until a new number is found
        }

        if (num == 9) {
          grid[i][j] = ' '; // If the number is 9, set it to a space
        } else {
          grid[i][j] = '0' + num;  // Otherwise, set it to the number
        }
        

        alreadySelected[num - 1] = num; // Mark the number as selected
    }
  }
}

bool Game::isValid(int row, int col) {
  return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

ostream &operator << (ostream &out, Game g) {
  for (int row = 0; row < g.SIZE; row++) {
    for (int col = 0; col < g.SIZE; col++) {
      if (col == 0) {
        out << '|';
      }
      out << g.grid[row][col] << '|';
    }
    out << endl;
  }

  return out;
}

void Game::movePiece(int num) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (grid[row][col] == '0' + num){
        for (int irow = -1; irow <= 1; ++irow) {
          for (int icol = -1; icol <= 1; ++icol) {
            if (irow == icol) continue; // avoid diagonal and same cell
            if (Game::isValid(row + irow, col + icol)) {
              if (grid[row + irow][col + icol] == ' ') {
                grid[row + irow][col + icol] = grid[row][col];
                grid[row][col] = ' ';
                return;
              }
            }
          }
        }
      }
    }
  }
}

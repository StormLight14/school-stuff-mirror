#include "TTTGrid.h"
#include <iostream>


TTTGrid::TTTGrid() {
  player = X;
}

void TTTGrid::selectMove(char choice) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (grid[row][col] == choice) {
        grid[row][col] = player;
        break;
      }
    }
  }
}

char TTTGrid::getCurrentPlayer() {
  return player;
}

ostream &operator <<(ostream &out, const TTTGrid &grid) {
  out << "+-+-+-+\n";

  for (int row = 0; row < grid.SIZE; row++) {
    for (int col = 0; col < grid.SIZE; col++) {
      if (col == 0) {
        out << "|";
      }
      out << grid.grid[row][col] << "|";
    }

    out << endl;
  }

  out << "+-+-+-+\n";
  return out;
}

bool TTTGrid::hasWon() {
  for (int row = 0; row < SIZE; row++) {
    if (grid[row][0] == player && grid[row][1] == player && grid[row][2] == player) {
      return true;
    }
  }

  for (int col = 0; col < SIZE; col++) {
    if (grid[0][col] == player && grid[1][col] == player && grid[2][col] == player) {
      return true;
    }
  }

  if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
    return true;
  }

  if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
    return true;
  }

  return false;
}

void TTTGrid::switchPlayer() {
  if (player == X) {
    player = O;
  } else {
    player = X;
  }
}

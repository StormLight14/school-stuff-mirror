#pragma once

#include <iostream>

using std::ostream, std::endl;

enum {X = 'X', O = 'O'};

class TTTGrid {
  public:
    const int SIZE = 3;
    TTTGrid();
    void switchPlayer();
    void selectMove(char);
    
    bool hasWon();
    char getCurrentPlayer();
    friend ostream &operator <<(ostream&, const TTTGrid&);
  private:
    char grid[3][3] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'}
    };
    char player;
};

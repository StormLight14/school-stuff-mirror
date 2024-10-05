#include <iostream>
#pragma once

using std::ostream;

class Game {
  public:
    Game();
    bool isValid(int, int);
    friend ostream &operator << (ostream &out, Game g);
    const int SIZE = 3;
  private:
    char grid [3][3] {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', ' '}
  };
};

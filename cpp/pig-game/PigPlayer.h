#pragma once

#include <string>
using std::string;

class PigPlayer {
  public:
    PigPlayer();
    void roll();
    void stop();
    void resetTurnTotal();
    string pickOption();
    int getDieValue();
    int getTurnTotal();
    int getTotal();
    bool isTurn;
  private:
    int dieValue;
    int turnTotal;
    int total;
};

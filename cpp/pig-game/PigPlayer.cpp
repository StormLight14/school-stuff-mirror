#include "PigPlayer.h"
#include <random>
#include <string>

using std::string;

PigPlayer::PigPlayer() {
  dieValue = 0;
  turnTotal = 0;
  total = 0;
  isTurn = false;
}

string PigPlayer::pickOption() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1);
  int randomNumber = dist(gen);

  if (randomNumber == 0) {
    return "stop";
  } else {
    return "roll";
  }
}

int PigPlayer::getDieValue() {
  return dieValue;
}

int PigPlayer::getTurnTotal() {
  return turnTotal;
}

int PigPlayer::getTotal() {
  return total;
}

void PigPlayer::roll() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 6);
  dieValue = dist(gen);

  if (getDieValue() == 1) {
    resetTurnTotal();
    stop();
  } else {
    turnTotal += getDieValue();
  }
}

void PigPlayer::stop() {
  total += turnTotal;
  resetTurnTotal();
  isTurn = false;
}

void PigPlayer::resetTurnTotal() {
  turnTotal = 0;
}

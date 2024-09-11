#include "game.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

bool isValidMove(int userMove, int stones) {
  if (userMove < 1 || userMove > 3 || userMove > stones) {
    return false;
  }

  return true;
}

void playerMove(int &stones) {
  int playerInput;
  std::cout << "How many stones will you take? " << std::endl;
  std::cin >> playerInput;
  if (isValidMove(playerInput, stones)) {
    stones -= playerInput;
  } else {
    std::cout << "Invalid amount." << std::endl;
    playerMove(stones);
  }
}

void computerMove(int &stones) {
  int takeAmount;
  if (stones > 0 && stones <= 4) {
    takeAmount = 1;
  } else {
    std::srand(std::time(0)); // seed for rand
    int rand_num = std::rand() % (4 - 1) + 1;
    takeAmount = rand_num;
  }

  std::cout << "Computer takes " << takeAmount << " stone(s)." << std::endl;
  stones -= takeAmount;
}

bool checkLose(int stones) {
  return (stones <= 0);
}

int randomStonesAmount() {
  std::srand(std::time(0));
  // range is rand % (maxNotInclusive - min) + min
  return std::rand() % (17 - 13) + 13;
}

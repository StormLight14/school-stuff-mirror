#include "game.cpp"
#include <iostream>

int main() {
  bool playingGame = true;
  int stones = randomStonesAmount();

  while (playingGame) {
    std::cout << "\nStones in the pile: " << stones << std::endl;
    playerMove(stones);
    if (checkLose(stones) == true) {
      std::cout << "Computer won the game!" << std::endl;
      break;
    }
    computerMove(stones);
    if (checkLose(stones) == true) {
      std::cout << "Player won the game!" << std::endl;
      break;
    }
  }

  return 0;
}


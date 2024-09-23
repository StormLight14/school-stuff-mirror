#include <iostream>
#include <iomanip>

using std::cout, std::cin, std::endl;

struct Position {
  int x;
  int y;
};

enum Direction {
  North,
  East,
  South,
  West
};

int getUserInput() {
  int input;
  cout << "1. North\n2. East\n3. South\n4. West\n5. Quit" << endl;
  cin >> input;
  return input;
}

void move(Position &position, Direction direction) {
  switch (direction) {
    case North: position.y++; break;
    case South: position.y--; break;
    case East: position.x++; break;
    case West: position.x--; break;
    default: return;
  }
}

void showPosition(Position &position) {
  cout << "Position: (" << position.x << ", " << position.y << ")" << endl;
}

int main() {
  Position position = {0, 0};

  while (true) {
    int input = getUserInput();
    Direction direction;

    switch (input) {
      case 1: direction = North; break;
      case 2: direction = East; break;
      case 3: direction = South; break;
      case 4: direction = West; break;
      case 5: return 0;
      default: cout << "Invalid input. Choose a number 1-5." << endl;
      continue;
    }

    move(position, direction);
    showPosition(position);
  }
}

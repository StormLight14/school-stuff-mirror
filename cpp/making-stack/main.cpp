#include "Stack.h"
#include <iostream>

using std::cout, std::endl;

int main() {
  cout << "Stack implemented with linked list!" << endl;
  Stack stack;
  stack.push("Lasagna");
  stack.push("Burger");
  stack.push("Ice Cream");
  stack.push("Watermelon");

  cout << stack << endl;
  stack.pop();
  stack.pop();
  stack.pop();
  cout << stack << endl;

  return 0;
}

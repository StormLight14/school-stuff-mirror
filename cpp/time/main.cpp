#include <iostream>
#include "Time.h"

using std::cout, std::endl;

int main() {
  cout << "Testing Time!" << endl;
  Time t1;
  Time t2(0, 14, 6, 1);
  Time t3(0, 24, 61, 43424);

  cout << t1 << endl;
  cout << t2 << endl;
  cout << t3 << endl;

  return 0;
}

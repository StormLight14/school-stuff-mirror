#include "Lookup.h"

using std::cout, std::cin, std::endl;

int main() {
  Lookup lookup;
  lookup.setElements();

  cout << "1. Search by Atomic Number\n2. Search by symbol\n3. Quit" << endl;
  int input;
  cin >> input;
  if (input == 1) {
    cout << "Enter the atomic number (1-118): ";
    int atomicNumber;
    cin >> atomicNumber;
    if (atomicNumber >= 1 && atomicNumber <= 118) {
      cout << "\n" << lookup.getElements()[atomicNumber - 1] << endl;
    } else {
      cout << "Enter a number from 1-118.";
    }
  } else if (input == 2) {

  }

  return 0;
}

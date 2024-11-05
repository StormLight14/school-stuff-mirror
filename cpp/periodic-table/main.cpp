#include "Lookup.h"

using std::cout, std::cin, std::endl, std::string;

int main() {
  Lookup lookup;
  lookup.setElements();

  while (true) {
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
        cout << "Enter the element's symbol: ";
        string symbol;
        cin >> symbol;
        for (int i = 0; i < 118; i++) {
          if (lookup.getElements()[i].symbol == symbol) {
            cout << "\n" << lookup.getElements()[i];
          }
        }
    } else {
      break;
    }
  }

  return 0;
}

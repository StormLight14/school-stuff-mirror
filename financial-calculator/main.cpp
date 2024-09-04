#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
  std::cout << "Financial Goal Calculator" << endl;

  // declare variables
  double investment, goal, rate;
  int years, choice;

  do {
    cout << "(1) Calculate years to financial goal" << endl;
    cout << "(2) Calculate amount based on years" << endl;
    cout << "(3) Quit" << endl;
    cin >> choice;

    if (choice <= 2) {
      cout << "Enter investment amount: ";
      cin >> investment;
      cout << "Enter interest rate: ";
      cin >> rate;

      rate /= 100;
    }

    switch (choice) {
      case 1:
        // calculate years to goal
        cout << "Enter financial goal: ";
        cin >> goal;

        while (investment < goal) {
          investment += (rate * investment);
          years++;
          cout << std::fixed << "Year " << std::setw(3) << years << ": " << std::setprecision(2) << investment << endl;
        }
        cout << "Years to goal: " << years << endl;

        break;
      case 2:
        // calculate amount based on years
        cout << "Enter the years you want to save for: ";
        cin >> years;
        for (int i = 0; i < years; i++) {
          investment += (rate * investment);
        }
        cout << "Your investment will be " << investment << " after " << years << " years.\n";

        break;
      case 3:
        break;
    }
  } while (choice < 3);

  return 0;
}



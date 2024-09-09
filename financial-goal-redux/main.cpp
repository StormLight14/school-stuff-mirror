#include <iostream>
#include <iomanip>
#include <tuple>

using std::cout, std::cin, std::endl;

int getChoice();
int yearsToGoal(float investment, float rate, float goal);
float getInvestmentGrowth(float investment, float rate, int years);
void getValues(float &investment, float &rate);

int main() {
  cout << "Financial Calculator Redux!" << endl;
  
  int choice;
  float investment, rate, goal;

  while (choice < 3) {
    choice = getChoice();

    if (choice == 1 || choice == 2) {
      getValues(investment, rate);
    }

    if (choice == 1) {
      cout << "Enter your financial goal: ";
      cin >> goal;
      cout << "Years to goal: " << yearsToGoal(investment, rate, goal) << endl;
    } else if (choice == 2) {
      cout << "Enter years you are saving for: ";
      int years;
      cin >> years;
      cout << "Your investment will grow to: " << getInvestmentGrowth(investment, rate, years) << endl;
    }
  }

  return 0;
}

int getChoice() {
  int choice;

  cout << "1. Calculate years to financial goal" << endl;
  cout << "2. Calculate amount based on years" << endl;
  cout << "3. Quit" << endl;

  cin >> choice;
  return choice;
}

void getValues(float &investment, float &rate) {
  cout << "Enter investment amount: ";
  cin >> investment;
  cout << "Enter interest rate: ";
  cin >> rate;
  rate /= 100;
}

int yearsToGoal(float investment, float rate, float goal) {
  int years = 0;
  while (investment < goal) {
    investment += investment * rate;
    years ++;
  }

  return years;
}

float getInvestmentGrowth(float investment, float rate, int years) {
  for (int i = 0; i < years; i++) {
    investment += investment * rate;
  }

  return investment;
}

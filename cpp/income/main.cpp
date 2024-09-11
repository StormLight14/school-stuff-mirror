#include <iostream>
#include <iomanip>

int main() {
  float total_income = 0;
  for (int i=0; i<5; i++) {
    float income;
    std::cout << "Enter income for " << 2012 + i << ": ";
    std::cin >> income;

    total_income += income;
  }

  std::cout << "Income (averaged over the past 5 years) is: $" << std::fixed << std::setprecision(2) << total_income / 5 << std::endl;
}


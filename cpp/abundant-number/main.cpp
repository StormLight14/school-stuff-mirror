#include <iostream>

int main() {
  while (true) {
    int num, divisorSum;
    std::cout << "Enter a number (-1 to quit): ";
    std::cin >> num;

    if (num == -1) {
      break;
    }

    for (int i=0; i<num; i++) {
      if (num % i == 0) {
        // std::cout << i << " is a divisor.\n";
        divisorSum += i;
      }
    }
    
    std::cout << num;
    if (divisorSum == num) {
      std::cout << " is an perfect number.\n";
    } else if (divisorSum > num) {
      std::cout << " is an abundant number.\n";
    } else {
      std::cout << " is a deficient number.\n";
    }

    divisorSum = 0;
  }
  
  return 0;
}



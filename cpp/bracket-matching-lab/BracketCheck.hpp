#pragma once
#include <iostream>

class BracketCheck {
  public:
    BracketCheck(std::string exp);
    int numBrackets(); // pairs of brackets
    bool isBalanced();
    friend std::ostream& operator<<(std::ostream& out, const BracketCheck& bc);
  private:
    std::string exp;
};

BracketCheck::BracketCheck(std::string exp) {
  exp = exp;
}

int BracketCheck::numBrackets() {
  int num = 0;
  for (char& c : exp) {
    if (c == '(' || c == '{' || c == '[') {
      num += 1;
    }
  }

  return num;
}

bool BracketCheck::isBalanced() {

}

std::ostream& operator<<(std::ostream& out, const BracketCheck& bc) {
  out << "";
  return out;
}


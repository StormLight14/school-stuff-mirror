#pragma once
#include <iostream>

class BracketCheck {
  public:
    BracketCheck(std::string exp);
    int numBrackets(); // pairs of brackets
    bool isBalanced();
    friend std::ostream& operator<<(std::ostream& out, const BracketCheck& bc);
};

std::ostream& operator<<(std::ostream& out, const BracketCheck& bc) {
  out << "";
  return out;
}



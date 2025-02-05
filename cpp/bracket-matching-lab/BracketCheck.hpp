#pragma once
#include <iostream>
#include <stack>

class BracketCheck {
  public:
    BracketCheck(std::string exp);
    int numBrackets() const; // pairs of brackets
    bool isBalanced() const;
    friend std::ostream& operator<<(std::ostream& out, const BracketCheck& bc);
  private:
    std::string exp;
};

BracketCheck::BracketCheck(std::string exp) {
  this->exp = exp;
}

int BracketCheck::numBrackets() const {
  int num = 0;
  for (char c : exp) {
    if (c == '(' || c == '{' || c == '[') {
      num += 1;
    }
  }

  return num;
}

bool BracketCheck::isBalanced() const {
  std::stack<char> bracketStack;
  for (char c : exp) {
    if (c == '(' || c == '[' || c == '{') {
      bracketStack.push(c);
    }

    else if (c == ')') {
      if (bracketStack.empty() || bracketStack.top() != '(') {
        return false;
      }

      bracketStack.pop();
    }

    else if (c == '}') {
      if (bracketStack.empty() || bracketStack.top() != '{') {
        return false;
      }

      bracketStack.pop();
    }

    else if (c == ']') {
      if (bracketStack.empty() || bracketStack.top() != '[') {
        return false;
      }
      bracketStack.pop();
    }
  }

  return bracketStack.empty();
}

std::ostream& operator<<(std::ostream& out, const BracketCheck& bc) {
  out << "expression: " << bc.exp << "\n";
  out << "balanced: " << bc.isBalanced() << "\n";
  out << "bracket pairs: " << bc.numBrackets() << "\n";
  return out;
}


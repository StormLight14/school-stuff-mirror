#pragma once

#include <string>
#include <iostream>

using std::string, std::ostream;

struct Node {
  std::string value;
  Node *next;
};

class Stack {
  public:
    Stack();
    ~Stack();
    // add a value to the stack
    void push(string value);
    // remove the top value from the stack
    void pop();
    // get top value
    string peek();
    // returns true if stack is empty
    bool isEmpty();
    friend ostream &operator << (ostream &, const Stack&);
  private:
    Node *top;
};

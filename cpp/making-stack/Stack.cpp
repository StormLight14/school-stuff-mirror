#include "Stack.h"
#include <iostream>

using std::ostream;

Stack::Stack() {
  top = nullptr;
}

Stack::~Stack() {
  // delete all of the stack!
  while (!isEmpty()) {
    pop();
  }
}

void Stack::push(string value) {
  Node *toAdd = new Node;
  toAdd->value = value;
  
  // stack is empty
  if (isEmpty()) {
    top = toAdd; // top points to new Node
    top->next = nullptr;

    // anything that isn't the first Node
  } else {
    toAdd->next = top;
    top = toAdd;
  }
}

bool Stack::isEmpty() {
  return top == nullptr;
}

string Stack::getTop() {
  return top->value;
}

void Stack::pop() {
  if (!isEmpty()) {
    Node *temp = top;
    top = top->next;
    delete temp;
  }
}

ostream& operator << (ostream &out, const Stack &stack) {
  Node *current = stack.top;
  while (current != nullptr) {
    out << current->value << " ";
    current = current->next;
  }
  return out;
}

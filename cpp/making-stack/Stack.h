#pragma once

#include <string>
#include <iostream>

using std::string, std::ostream;

struct Node {
  std::string value;
  Node *next;
};
template<typename T> class Stack;
template<typename T> ostream &operator << (ostream &, const Stack<T>&);

template<typename T> class Stack {
  public:
    Stack();
    ~Stack();
    // add a value to the stack
    void push(T);
    // remove the top value from the stack
    void pop();
    // get top value
    T peek();
    // returns true if stack is empty
    bool isEmpty();
    friend ostream &operator << <>(ostream &, const Stack<T>&);
  private:
    Node *top;
};

template<typename T>
Stack<T>::Stack() {
    top = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(T value) {
    auto toAdd = new Node;
    toAdd->value = value;

    if (isEmpty()) {
        top = toAdd;
        top->next = nullptr;
    } else {
        toAdd->next = top;
        top = toAdd;
    }
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template<typename T>
T Stack<T>::peek() {
    return top->value;
}

template<typename T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        auto temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
ostream &operator<<(ostream &out, const Stack<T> &stack) {
    auto current = stack.top;
    while (current != nullptr) {
        out << current->value << ", ";
        current = current->next;
    }
    return out;
}

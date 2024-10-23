#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using std::ostream, std::string;

template<typename T> class Node;

template<typename T> class Node {
  public:
    Node();
    Node(T data);
    Node* next;
    T data;
};

template<typename T> 
class Queue;

template<typename T> 
ostream &operator << (ostream &, const Queue<T>&);

template<typename T> class Queue {
  public:
    Queue();
    ~Queue();

    // checks if Queue is empty
    bool isEmpty();
    // adds element to the front
    void add(T value);
    // removes element from the back
    void remove();
    // returns the front element, if it exists
    T peek();
    template<typename Y>
    friend ostream &operator << (ostream &out, const Queue<Y> &s);
  private:
    Node<T>* front;
    Node<T>* back;
};

template<typename T>
Node<T>::Node() {
  data = "";
  next = nullptr;
}

template<typename T>
Node<T>::Node(T data) {
  this->data = data;
  next = nullptr;
}

template<typename T>
Queue<T>::Queue() {
  front = nullptr;
  back = nullptr;
}

template<typename T>
Queue<T>::~Queue() {
  while (!isEmpty()) {
    remove();
  }
}

template<typename T>
bool Queue<T>::isEmpty() {
  return front == nullptr;
}

template<typename T>
void Queue<T>::add(T value) {
  Node<T>* newNode = new Node(value);
  if (isEmpty()) {
    front = newNode;
  } else {
    back->next = newNode;
  }
  back = newNode;
}

template<typename T>
void Queue<T>::remove() {
  if (!isEmpty()) {
    Node<T> *temp = front;
    front = front->next; // move front over to the next node

    if (front == nullptr) {
      back = nullptr;
    }

    delete temp; // delete mem of old front node
  }
}

template<typename T>
T Queue<T>::peek() {
  if (!isEmpty()) {
    return front->data;
  }
  throw std::runtime_error("Queue is empty");
}

template<typename T>
ostream &operator << (ostream &out, const Queue<T> &q) {
  Node<T> *current = q.front;
  while (current != nullptr) {
    out << current->data << ", ";
    current = current->next;
  }
  return out;
}

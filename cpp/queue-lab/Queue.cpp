#include "Queue.h"

using std::string;

Node::Node() {
  data = "";
  next = nullptr;
}

Node::Node(string data) {
  this->data = data;
  next = nullptr;
}

Queue::Queue() {
  front = nullptr;
  back = nullptr;
}

Queue::~Queue() {
  while (!isEmpty()) {
    remove();
  }
}

bool Queue::isEmpty() {
  return front == nullptr;
}

void Queue::add(string value) {
  Node* newNode = new Node(value);
  if (isEmpty()) {
    front = newNode;
  } else {
    back->next = newNode;
  }
  back = newNode;
}

void Queue::remove() {
  if (!isEmpty()) {
    Node *temp = front;
    front = front->next; // move front over to the next node

    if (front == nullptr) {
      back = nullptr;
    }

    delete temp; // delete mem of old front node
  }
  
}

string Queue::peek() {
  if (!isEmpty()) {
    return front->data;
  }
  return "";
}

ostream &operator << (ostream &out, const Queue &q) {
  Node *current = q.front;
  while (current != nullptr) {
    out << current->data << ", ";
    current = current->next;
  }
  return out;

}

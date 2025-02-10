#pragma once
#include <memory>

using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

template<typename Type>
struct Node {
  Type data;
  shared_ptr<Node<Type>> next;
};

template<typename Type>
class LinkedList;

template<typename Type>
ostream& operator<<(ostream& out, const LinkedList<Type>& list);

template<typename Type>
class LinkedList{
  public:
    LinkedList(): front(nullptr), back(nullptr), count(0) {}// Default constructor for the LinkedList. Creates an empty list by setting front and back of the list to nulllptr
    //~LinkedList(); // creates an empty list by setting front and back of the list to nullptr
    void insert(Type data); //Adds to the back of the list
    Type peek(int ndx)const ;//Looks at an element at the given ndx value
    void remove(int ndx); //Removes an element at the given ndx position
    friend std::ostream& operator<< <>(std::ostream& out, const LinkedList<Type>& list);
    //LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList
  protected:
    int count;
    shared_ptr<Node<Type>> front;
    shared_ptr<Node<Type>> back;
};

template<typename Type>
void LinkedList<Type>::insert(Type data) {
  auto temp = make_shared<Node<Type>>();
  temp->data = data;
  temp->next = nullptr;

  if (!front) {
    front = temp;
    back = temp;
  } else {
    back->next = temp;
    back = temp;
  }

  count += 1;
}

template<typename Type>
Type LinkedList<Type>::peek(int idx) const {
  if (idx >= count || idx < 0) {
    throw runtime_error("index out of range.");
  }

  int currentNodeIdx = 0;
  auto currentNode = front;

  while (currentNodeIdx < idx) {
    currentNodeIdx += 1;
    currentNode = currentNode->next;
  }

  return currentNode->data;
}

template<typename Type>
void LinkedList<Type>::remove(int idx) {
  if (idx >= count || idx < 0) {
    throw runtime_error("index out of range.");
  }

  // removing front
  if (idx == 0) {
    auto toDelete = front;
    front = toDelete->next;
    //delete toDelete;
    return;
  }

  int currentNodeIdx = 0;
  auto currentNode = front;

  while (currentNodeIdx < idx-1) {
    currentNodeIdx += 1;
    currentNode = currentNode->next;
  }

  auto toDelete = currentNode->next;
  if (toDelete->next) {
    currentNode->next = toDelete->next;
  } else {
    currentNode->next = nullptr;
    back = currentNode;
  }
  count -= 1;
  // delete toDelete;
}

template<typename Type>
ostream& operator<<(ostream& out, const LinkedList<Type>& list) {
  auto currentNode = list.front;
  while (currentNode) {
    out << currentNode->data;
    if (currentNode->next) {
      out << " ";
    }
    currentNode = currentNode->next;
  }

  return out;
}
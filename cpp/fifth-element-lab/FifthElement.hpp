#include "LinkedList.hpp"

template<typename T>
class FifthElement : public LinkedList<T> {
public:
    T getFifthElement();
    void insertNewFifthElement(const T& value);
    void deleteFifthElement();
    void swapFourthAndFifthElement();
};

template<typename T>
T FifthElement<T>::getFifthElement() {
  shared_ptr<Node<T>> currentNode = this->front;
  for (int i = 0; i < 4 && currentNode != nullptr; i++) {
    currentNode = currentNode->next;
  }

  if (!currentNode) throw runtime_error("Fifth element doesn't exist.");
  return currentNode->data;
}

template<typename T>
void FifthElement<T>::insertNewFifthElement(const T& value) {
  shared_ptr<Node<T>> currentNode = this->front;
  for (int i = 0; i < 3 && currentNode != nullptr; i++) {
    currentNode = currentNode->next;
  }
  if (!currentNode) throw runtime_error("The list is too short to insert a 5th element.");

  auto newNode = make_shared<Node<T>>();
  newNode->data = value;
  newNode->next = currentNode->next;
  currentNode->next = newNode;
}

template<typename T>
void FifthElement<T>::deleteFifthElement() {
  shared_ptr<Node<T>> currentNode = this->front;
  for (int i = 0; i < 3 && currentNode != nullptr; i++) {
    currentNode = currentNode->next;
  }
  if (!currentNode || !currentNode->next) throw runtime_error("fourth/fifth element doesn't exist.");

  currentNode->next = currentNode->next->next;
}

template<typename T>
void FifthElement<T>::swapFourthAndFifthElement() {
  shared_ptr<Node<T>> third = this->front;
    for (int i = 0; i < 2 && third != nullptr; i++) {
        third = third->next;
    }
    if (!third || !third->next || !third->next->next) throw runtime_error("third/fourth/fifth element does not exist");
    auto fourth = third->next; // 13
    auto fifth = fourth->next; // 14
    auto sixth = fifth->next; // 15

    // 10 11 12 14 13 15 16 17 18 19
    third->next = fifth; // 12->next = 14
    fifth->next = fourth; // 14->next = 13
    fourth->next = sixth; // 13->next = 15
}
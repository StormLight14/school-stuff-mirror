#include <iostream>
#include <string>

using std::ostream, std::string;

class Node {
  public:
    Node();
    Node(string);
    Node* next;
    string data;
};

class Queue {
  public:
    Queue();
    ~Queue();

    // checks if Queue is empty
    bool isEmpty();
    // adds element to the front
    void add(string value);
    // removes element from the back
    void remove();
    // returns the front element, if it exists
    string peek();

    friend ostream &operator << (ostream &out, const Queue &s);
  private:
    Node* front;
    Node* back;
};


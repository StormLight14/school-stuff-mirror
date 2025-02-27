#include <iostream>
#include <memory>

using std::ostream, std::shared_ptr, std::make_shared, std::runtime_error;

template <typename T>
struct Node {
  Node(T data): data(data), next(nullptr) {};
  T data;
  shared_ptr<Node<T>> next;
};

template <typename T>
class MyStack;

template <typename T>
ostream& operator <<(ostream& out, const MyStack<T>& q);

template <typename T>
class MyStack
{
  public:
    MyStack();					//Constructor
    MyStack(const MyStack&);	//Copy Constructor
    //~Queue();					//Destructor if using raw pointers
    void push(T item);		//Adds an item 
    void pop();					//Removes an item 
    T peek();				//Returns the top value
    int size();					//Returns the size
    bool isEmpty();				//Returns true if empty
    void clear();				//Erases all the items
    MyStack<T>& operator=(const MyStack<T>& other);	//Deep copy
    friend ostream& operator<< <>(ostream& out, const MyStack<T>& q);  //Displays all the items

  private:
    shared_ptr<Node<T>> top;
    int count;
};

template <typename T>
MyStack<T>::MyStack() {
  top = nullptr;
  count = 0;
}
template <typename T>
MyStack<T>::MyStack(const MyStack<T>& other) {
	count = 0;
	auto temp = other.front;
  top = make_shared<Node<T>>(temp->data);
  count++;
  auto current = top;

  for (int i=0; i<other.count; i++) {
    auto newPtr = make_shared<Node<T>>(temp->data);
    current->next = newPtr;
    temp = temp->next;
    count++;
  }
}



/*
template <typename T>
Queue<T>::~Queue() {

}

*/
template <typename T>
void MyStack<T>::push(T item) {
  auto temp = make_shared<Node<T>>(item);

  if (count == 0) {
    top = temp;
  } else {
    temp->next = top;
    top = temp;
  }

  count++;
}

template <typename T>
T MyStack<T>::peek() {
  if (top == nullptr || count == 0) { 
    throw runtime_error("No elements in Stack.");
  }

  return top->data;
}

template <typename T>
int MyStack<T>::size() {
	return count;
}
template <typename T>
bool MyStack<T>::isEmpty() {
	return count == 0;
}

template <typename T>
void MyStack<T>::clear() {
  top = nullptr; // smart pointer will automatically deallocate
  count = 0;
}

template <typename T>
void MyStack<T>::pop() {
  if (top == nullptr) {
    throw runtime_error("No elements in Stack.");
  }

  top = top->next;
  count--;
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack& other) {

	return *this;
}

template <typename T>
ostream& operator<<(ostream& out, const MyStack<T>& q)
{
	auto temp = q.top;
	while (temp) {
		out << temp->data;
		if (temp->next) out << " ";
		temp = temp->next;
	}
	return out;
}

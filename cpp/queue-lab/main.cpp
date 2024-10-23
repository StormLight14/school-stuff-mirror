#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
void check(string name, T, T);
template <class T>
void fillQueue(Queue<T>&);
template <class T>
void testIsEmpty();
template <class T>
void checkQueueOrder();

int main() {
  testIsEmpty<int>();
  checkQueueOrder<int>();
}

template <class T>
void fillQueue(Queue<T> &queue){
  queue.add(1);
  queue.add(2);
  queue.add(3);
  queue.add(4);
  cout << queue << endl;
}
template <class T>
void testIsEmpty(){
  Queue<T> queue;
  check("1. Checking Empty Queue", queue.isEmpty(), true);
  queue.add(1);
  queue.remove();
  check("2. Checking Recently Empty Queue", queue.isEmpty(), true);
}

template <class T>
void checkQueueOrder(){
  Queue<T> queue;
  fillQueue(queue);
  int txt = 1;
  check("3. Check Front: ", queue.peek(), txt);
  queue.remove();
  txt = 2;
  check("4. Check Second: ", queue.peek(), txt);
}

template <class T>
void check(string name, const T shouldBe, const T currentlyIs){
  if(shouldBe == currentlyIs){
    cout << name << ": Passed " << endl;
  }
  else{
    cout << name << ": Failed, value should be " << shouldBe << " but is returning " << currentlyIs << endl;
  }
}

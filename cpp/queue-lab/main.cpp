#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
void check(string, T, T);
template <class T>
void fillQueue(Queue<T>&);
template <class T>
void testIsEmpty();
template <class T>
void checkQueueOrder();

int main() {
  testIsEmpty<string>();
  checkQueueOrder<string>();
}

template <class T>
void fillQueue(Queue<T> &queue){
  queue.add("one");
  queue.add("two");
  queue.add("three");
  queue.add("four");
  cout << queue << endl;
}
template <class T>
void testIsEmpty(){
  Queue<T> queue;
  check("1. Checking Empty Queue", queue.isEmpty(), true);
  queue.add("one");
  queue.remove();
  check("2. Checking Recently Empty Queue", queue.isEmpty(), true);
}

template <class T>
void checkQueueOrder(){
  Queue<T> queue;
  fillQueue(queue);
  string txt = "one";
  check("3. Check Front: ", queue.peek(), txt);
  queue.remove();
  txt = "two";
  check("4. Check Second: ", queue.peek(), txt);
}

template <class type>
void check(string name, const type shouldBe, const type currentlyIs){
  if(shouldBe == currentlyIs){
    cout << name << ": Passed " << endl;
  }
  else{
    cout << name << ": Failed, value should be " << shouldBe << " but is returning " << currentlyIs << endl;
  }
}

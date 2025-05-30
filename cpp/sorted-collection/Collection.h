#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

template<typename Item>
class Collection;

template<typename Item>
ostream& operator << (ostream& out, const Collection<Item>& c);

template<typename Item>
class Collection {
public:
  Collection();
  Collection(int size);
  Collection(const Collection<Item>& a);
  virtual int size();
  virtual Item get(int ndx) const;
  virtual void add(Item e);
  virtual void removeEnd();
  virtual Collection<Item>& operator=(Collection<Item>& a);
  virtual Item operator[](int index);
  virtual void operator-(int num);
  void expand();
  
  friend ostream& operator<< (ostream& out, const Collection& c){
    return out;
  }

protected:
  int capacity;
  int curSize;
  static const int INITIAL_CAPACITY = 8;
  unique_ptr<Item[]> elements;
};

template<typename Item>
Collection<Item>::Collection(){
  capacity = INITIAL_CAPACITY;
  curSize = 0;
  elements = make_unique<Item[]>(capacity);
}

template<typename Item>
Collection<Item>::Collection(int size){
  capacity = size;
  curSize = 0;
  elements = make_unique<Item[]>(capacity);
}

template<typename Item>
Collection<Item>::Collection(const Collection<Item>& a){
  capacity = a.capacity;
  curSize = a.curSize;
  elements = make_unique<Item[]>(capacity);

  // deep copy of `a` class
  for (int i=0; i < curSize; i++) {
    elements[i] = a.elements[i];
  }
}

template<typename Item>
int Collection<Item>::size() {
  return curSize;
}

template<typename Item>
Item Collection<Item>::get(int index) const {
 return elements[index];
}

template<typename Item>
void Collection<Item>::add(Item e) {
  if (curSize == capacity) {
    expand();
  }
  elements[curSize] = e;

  curSize++;
}

template<typename Item>
void Collection<Item>::removeEnd() {
  curSize--;
  if (curSize < 0) {
    throw runtime_error("List is already empty.");
  }
}

template<typename Item>
Collection<Item>& Collection<Item>::operator=(Collection<Item>& a) {
  auto newElements = make_unique<Item[]>(a.capacity);
  for (int i=0; i<a.curSize; i++) {
    newElements[i] = a.elements[i];
  }

  elements = move(newElements);
  capacity = a.capacity;
  curSize = a.curSize;

  return *this;
}

template<typename Item>
Item Collection<Item>::operator[](int index) {
  return get(index);
}

template<typename Item>
void Collection<Item>::expand() {
  auto newElements = make_unique<Item[]>(capacity + 1);

  for (int i=0; i<capacity; i++) {
    newElements[i] = elements[i];
  }

  elements = move(newElements);
  capacity += 1;
}

template<typename Item>
void Collection<Item>::operator-(int num) {
  for (int i=0; i<num; i++) {
    removeEnd();
  }
}

template<typename Item>
ostream& operator<<(ostream& out, const Collection<Item>& c) {
  for (int i=0; i<c.curSize; i++) {
    out << c.elements[i];
    if (i < c.curSize - 1) {
      out << " ";
    }
    
    return out;
  }
}
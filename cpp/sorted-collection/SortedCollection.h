#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "Collection.h"

using namespace std;

template<typename Item>
class Collection;

template<typename Item>
ostream& operator<<(ostream& out, const Collection<Item>& c);

template<typename Item>
class SortedCollection : public Collection<Item> {
public:
  SortedCollection();
  SortedCollection(int size);
  SortedCollection(const SortedCollection<Item>& a);

  SortedCollection<Item>& operator+(const Item& e);
  SortedCollection<Item>& operator<<(const Item& e);
  void add(Item e) override;

// fix all the super annoying not declared crap thanks stack overflow
protected:
  using Collection<Item>::capacity;
  using Collection<Item>::curSize;
  using Collection<Item>::elements;
  using Collection<Item>::INITIAL_CAPACITY;
};

template<typename Item>
SortedCollection<Item>::SortedCollection() : Collection<Item>() {}

template<typename Item>
SortedCollection<Item>::SortedCollection(int size) : Collection<Item>(size) {}

template<typename Item>
SortedCollection<Item>::SortedCollection(const SortedCollection<Item>& a) : Collection<Item>(a) {}

template<typename Item>
SortedCollection<Item>& SortedCollection<Item>::operator+(const Item& e) {
  this->add(e);  
  return *this;
}

template<typename Item>
SortedCollection<Item>& SortedCollection<Item>::operator<<(const Item& e) {
  this->add(e);  
  return *this;
}

template<typename Item>
void SortedCollection<Item>::add(Item e) {
  if (curSize == capacity) {
    this->expand();
  }

  int i = curSize - 1;
  while (i >= 0 && elements[i] > e) {
    elements[i + 1] = elements[i];
    i--;
  }
  elements[i + 1] = e;
  curSize++;
}

template<typename Item>
ostream& operator<<(ostream& out, const SortedCollection<Item>& c) {
  for (int i = 0; i < c.curSize; i++) {
    out << c.elements[i];
    if (i < c.curSize - 1) {
      out << " ";
    }
  }
  return out;
}

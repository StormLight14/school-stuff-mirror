#pragma once

#include <iostream>
#include <vector>

template<typename T>
class Range;

template<typename T>
std::ostream& operator<<(std::ostream& out, const Range<T>& r);

template<typename T>
class Range {
  public:
    Range(T start, T end): start(start), end(end), step(1) {
      createValues();
    }
    Range(T start, T end, T step): start(start), end(end), step(step) {
      createValues();
    }
    int length();
    T sum();
    T average();
    T min();
    T max();
    void createValues();
  private:
    T start;
    T end;
    T step;
    std::vector<T> values = {};
};

template<typename T>
int Range<T>::length() {
  return values.size();
}

template<typename T>
T Range<T>::sum() {
  int total = 0;

  for (auto& n : values) {
    total += n;
  }

  return total;
}

template<typename T>
T Range<T>::average() {
  return sum() / length();
}

template<typename T>
T Range<T>::min() {
  return values[0];
}

template<typename T>
T Range<T>::max() {
  return values[length()];
}

template<typename T>
void Range<T>::createValues() {
  for (int i=0; i<end; i+=step) {
    values.push_back(i);
  }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Range<T>& r) {
  out << "TEST!!";
}
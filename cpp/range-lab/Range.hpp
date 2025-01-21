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
  T total = T();

  for (auto& n : values) {
    total += n;
  }

  return total;
}

template<typename T>
T Range<T>::average() {
  if (length() != 0) {
    return sum() / length();
  } else {
    return 0;
  }
}

template<typename T>
T Range<T>::min() {
  if (step > 0) {
    return values[0];
  } else {
    return values[length() - 1];
  }
  
}

template<typename T>
T Range<T>::max() {
  if (step > 0) {
    return values[length() - 1];
  } else {
    return values[0];
  }
}

template<typename T>
void Range<T>::createValues() {
    T currentValue = start;
    
    if (step == 0) {
        throw std::invalid_argument("ya can't make step 0 cause that'd make an infinite loop, silly goose");
    }

    while ((step >= 0 && currentValue <= end) || (step <= 0 && currentValue >= end)) {
        values.push_back(currentValue);
        currentValue += step;
    }
}



template<typename T>
std::ostream& operator<<(std::ostream& out, const Range<T>& r) {
  out << "TEST!!";
}
#pragma once

using namespace std;
#include <iostream>;

template <typename T>
class Point{
    private:
        T x;
        T y;

    public:
        Point(){x=0; y=0;}
        Point(T x, T y): x(x), y(y){}
        Point operator+(const Point&);
        Point operator+=(const Point&);
        Point operator-(const Point&);
        Point operator-=(const Point&);
        friend ostream& operator<<(ostream& out, const Point& p);
        friend istream& operator>>(istream& in, Point& p);
};

template <typename T>
Point<T> Point<T>::operator+(const Point& pToAdd) {
  return Point(x + pToAdd.x, y + pToAdd.y);
}

template <typename T>
Point<T> Point<T>::operator+=(const Point& pToAdd) {
  x += pToAdd.x;
  y += pToAdd.y;
  return *this;
}

template <typename T>
Point<T> Point<T>::operator-(const Point& pToSubtract) {
  return Point(x - pToSubtract.x, y - pToSubtract.y);
}

template <typename T>
Point<T> Point<T>::operator-=(const Point& pToSubtract) {
  x -= pToSubtract.x;
  y -= pToSubtract.y;
  return *this;
}

template <typename T>
ostream& operator<<(ostream& out, const Point<T>& p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

template <typename T>
istream& operator>>(istream& in, Point<T>& p) {
  in >> p.x >> p.y;
  return in;
}

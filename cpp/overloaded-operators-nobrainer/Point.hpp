#pragma once

using namespace std;
#include <iostream>;

class Point{
    private:
        int x;
        int y;

    public:
        Point(){x=0; y=0;}
        Point(int x, int y): x(x), y(y){}
        Point operator+(const Point&);
        Point operator+=(const Point&);
        Point operator-(const Point&);
        Point operator-=(const Point&);
        friend ostream& operator<<(ostream& out, const Point& p);
        friend istream& operator>>(istream& in, Point& p);
};

Point Point::operator+(const Point& pToAdd) {
  return Point(x + pToAdd.x, y + pToAdd.y);
}

Point Point::operator+=(const Point& pToAdd) {
  x += pToAdd.x;
  y += pToAdd.y;
  return *this;
}

Point Point::operator-(const Point& pToSubtract) {
  return Point(x - pToSubtract.x, y - pToSubtract.y);
}

Point Point::operator-=(const Point& pToSubtract) {
  x -= pToSubtract.x;
  y -= pToSubtract.y;
  return *this;
}

ostream& operator<<(ostream& out, const Point& p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

istream& operator>>(istream& in, Point& p) {
  in >> p.x >> p.y;
  return in;
}
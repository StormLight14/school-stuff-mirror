#pragma once

#include <iostream>

using std::ostream;

class Time {
  public:
    Time();
    Time(int, int, int, int);
    Time operator + (Time);
    Time operator += (int);
    friend ostream& operator << (ostream &out, Time &t);
    void fixOverflow();
  private:
    int days, hours, minutes, seconds;
};


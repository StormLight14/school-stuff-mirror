#include "Time.h"
#include <iostream>

using std::ostream;

Time::Time() {
  days = 0;
  hours = 0;
  minutes = 0;
  seconds = 0;
}

Time::Time(int h, int m, int s) {
  days = 0;
  hours = h;
  minutes = m;
  seconds = s;

  fixOverflow();
}

ostream& operator << (ostream &out, Time &t) {
  if (t.days < 10) out << "0";
  out << t.days << ":";

  if (t.hours < 10) out << "0";
  out << t.hours << ":";
  
  if (t.minutes < 10) out << "0";
  out  << t.minutes << ":";
  
  if (t.seconds < 10) out << "0";
  out << t.seconds;
  return out;
}

void Time::fixOverflow() {
  if (seconds > 59) {
    minutes += seconds / 60;
    seconds = seconds % 60;
  }
  if (minutes > 59) {
    hours += minutes / 60;
    minutes %= 60;
  }
  if (hours > 23) {
    days += hours / 24;
    hours %= 24;
  }
}

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
  while (seconds > 59 || minutes > 59 || hours > 23) {
    if (seconds > 59) {
      minutes += 1;
      seconds = 0 + seconds - 59;
    }
    if (minutes > 59) {
      hours += 1;
      minutes = 0 + minutes - 59;
    }
    if (hours > 23) {
      days += 1;
      hours = 0 + hours - 23;
    }
  }
}

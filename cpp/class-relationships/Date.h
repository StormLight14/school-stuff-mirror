#pragma once
#include <iostream>

class Date {
  public:
    Date(int year, int month, int day): year(year), month(month), day(day) {}
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
  
  protected:
    int year;
    int month;
    int day;

};

std::ostream& operator<<(std::ostream& out, const Date& date) {
  out << date.month << "-" << date.day << "-" << date.year;
  return out;
}

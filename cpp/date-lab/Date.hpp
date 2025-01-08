#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
  Date(int y): year(y), month(1), day(1) {}
  Date(int y, int m): year(y), month(m), day(1) {}
  Date(int y, int m, int d): year(y), month(m), day(d){}

  int getYear() {
    return year;
  }

  int getMonth() {
    return month;
  }

  string getMonthString() {
    switch (month) {
      case 1:
        return "Jan";
        break;
      case 2:
        return "Feb";
        break;
      case 3:
        return "Mar";
        break;
      case 4:
        return "Apr";
        break;
      case 5:
        return "May";
        break;
      case 6:
        return "June";
        break;
      case 7:
        return "July";
        break;
      case 8:
        return "Aug";
        break;
      case 9:
        return "Sep";
        break;
      case 10:
        return "Oct";
        break;
      case 11:
        return "Nov";
        break;
      case 12:
        return "Dec";
        break;
    }

    return "";
  }

  int getDay() {
    return day;
  }

  Date& addMonths(int n){
    year  += (month + n) / 12;
    month = (month + n) % 12;
    return *this;
  }

  Date& addDays(int n) {
    int d = daysToDate() + n;
    int y = year, m = 1;
    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }
    day = d;
    month = m;
    year = y;

    return *this;
  }

  static bool isLeapYear(int y) {
    return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
  }

  string toString() {
    // TODO: complete this function implementation here.
    std::stringstream ss;
    ss << getMonthString() << " " << getDay() << ", " << getYear();
    return ss.str();
  }

  int daysToDate(){
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for(int m = 0; m < month - 1; m++){
      days += days_in_month[m];
    }
    days += day;
    return days;
  }

  // TODO: Overload operator+ here
Date operator+(int days) {
    Date newDate(year, month, day);
    newDate.addDays(days);
    return newDate;
}

  // TODO: overload operator<< here
friend ostream& operator << (ostream &out, Date &d) {
    out << d.toString();
    return out;
  }


private:
  int year, month, day;

  static int daysInMonth(int y, int m){
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
  }
};


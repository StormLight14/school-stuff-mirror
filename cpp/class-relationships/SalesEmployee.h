#pragma once

#include <iostream>
#include <sstream>
#include "SalariedEmployee.h"

using std::string;

class SalesEmployee: public SalariedEmployee {
  public:
    SalesEmployee(string name, int year, int month, int day, double salary, double commission, double sales) : SalariedEmployee(name, year, month, day, salary), sales(sales), commission(commission) {}
    string toString() const;
  protected:
    double sales, commission;
};

string SalesEmployee::toString() const {
  std::stringstream ss;
  ss << SalariedEmployee::toString();
  ss << "Sales: " << sales << std::endl;
  ss << "Commission: " << commission;
  return ss.str();
}

#pragma once
#include <sstream>
#include <iostream>
#include "Employee.h"

using std::string;

class WagedEmployee: public Employee {
  public:
    WagedEmployee(string name, int year, int month, int day, double wage, double hours) : Employee(name, year, month, day), wage(wage), hours(hours) {}
    string toString() const;
  protected:
    double wage;
    double hours;
};

string WagedEmployee::toString() const {
  std::stringstream ss;
  ss << Employee::toString();
  ss << "Wage: " << wage << " Hours: " << hours << std::endl;
  ss << "Salary: " <<  wage * hours << std::endl;
  return ss.str();
}

#pragma once

#include <iostream>
#include <sstream>
#include "Employee.h"

using std::string;

class SalariedEmployee: public Employee {
  public:
    SalariedEmployee(string name, int year, int month, int day, double salary) : Employee(name, year, month, day), salary(salary) {}
    virtual string toString() const;
  protected:
    double salary;
};

string SalariedEmployee::toString() const {
  std::stringstream ss;
  ss << Employee::toString();
  ss << "Salary: " << salary << std::endl;
  return ss.str();
}

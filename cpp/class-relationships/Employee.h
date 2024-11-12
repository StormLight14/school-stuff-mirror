#pragma once

#include <iostream>
#include <sstream>
#include "Date.h"
#include "Address.h"

using std::string;

class Employee {
  public:
    Employee(string name, int year, int month, int day) : name(name), address(address), startDate(year, month, day) {}
    virtual string toString() const;
    void setAddress(string street, string city);
    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
    ~Employee();
  protected:
    string name;
    Address* address;
    Date startDate;
};

Employee::~Employee() {
  delete address;
}

void Employee::setAddress(string street, string city) {
  address = new Address(street, city);
}

string Employee::toString() const {
  std::stringstream ss;
  ss << name << std::endl;
  ss << startDate << std::endl;

  if (address) {
    ss << *address << std::endl;
  }

  return ss.str();
}

std::ostream& operator<<(std::ostream& out, const Employee& employee) {
  out << employee.toString();
  return out;
}

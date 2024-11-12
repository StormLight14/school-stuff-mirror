#pragma once
#include <iostream>

using std::string;

class Address {
  public:
    Address(string street, string city) : street(street), city(city) {}
    friend std::ostream& operator<<(std::ostream& out, const Address& address);
  
  protected:
    string street;
    string city;
};

std::ostream& operator<<(std::ostream& out, const Address& address) {
  out << address.street << ", " << address.city;
  return out;
}

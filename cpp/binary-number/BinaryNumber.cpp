#include "BinaryNumber.h"
#include <string>
#include <iostream>
using std::string, std::ostream;

using std::string;

int binaryToDecimal(string binary) {
  return std::stoi(binary, nullptr, 2);
}

string decimalToBinary(int num) {
  if (num == 0) return "0";

  string binary;

  while (num > 0) {
    binary.insert(binary.begin(), (num % 2) + '0');
    num /= 2;
  }

  return binary;
}

BinaryNumber::BinaryNumber(string binary) {
  value = binaryToDecimal(binary);
}

BinaryNumber::BinaryNumber(int num) {
  value = num;
}

BinaryNumber::BinaryNumber() {
  value = 0;
}

int BinaryNumber::getDecimal() {
  return value;
}

string BinaryNumber::getBinary() {
  return decimalToBinary(value);
}

ostream& operator << (ostream &out, BinaryNumber num) {
  out << decimalToBinary(num.value);
  return out;
}

BinaryNumber BinaryNumber::operator + (BinaryNumber num) {
  return BinaryNumber(value + num.value);
}

BinaryNumber BinaryNumber::operator - (BinaryNumber num) {
  int result;
  result = value - num.value;
  if (result < 0) {
    result = 0;
  }

  return BinaryNumber(result);
}

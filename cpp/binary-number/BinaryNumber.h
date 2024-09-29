#include <string>
#include <iostream>
using std::string, std::ostream;

class BinaryNumber {
  public:
    BinaryNumber();
    BinaryNumber(int);
    BinaryNumber(string);
    int getDecimal();
    string getBinary();
    friend ostream& operator << (ostream &out, BinaryNumber num);
    BinaryNumber operator + (BinaryNumber num);
    BinaryNumber operator - (BinaryNumber num);
  private:
    int value;
};

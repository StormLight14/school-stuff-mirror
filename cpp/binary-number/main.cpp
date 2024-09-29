#include <iostream>
#include <sstream>
#include "BinaryNumber.h"

using namespace std;

template<typename Type>
bool test(string name, Type is, Type shouldBe);
void testConstructor();
void testConversions();
void testSubtraction();
void testAddition();


int main()
{
    cout << "BinaryNumber Class Testing: " << endl;
    testConstructor();
    testConversions();
    testAddition();
    testSubtraction();
    return 0;
}

void testConstructor(){
    BinaryNumber b1("1101");
    stringstream str;
    str << b1;
    string name = "Constructor";
    string ans = "1101";
    test(name, str.str(), ans);
}
void testConversions(){
    BinaryNumber b1(13);
    stringstream str;
    str << b1;
    string name = "Conversions";
    string ans = "1101";
    test(name, str.str(), ans);
}

void testAddition(){
    BinaryNumber b1(13);
    
    BinaryNumber b2("1101");
    BinaryNumber b3 = b1 + b2;
    stringstream str;
    str << b1;


    string name = "Addition: B1 retains value";
    string ans = "1101";
    test(name, str.str(), ans);
    str.str("");

    str << b2;
    name = "Addition: B2 retains value";
    ans = "1101";
    test(name, str.str(), ans);
    str.str("");

    str << b3;
    name = "Addition Operator";
    ans = "11010";
    test(name, str.str(), ans);
}

void testSubtraction(){
    BinaryNumber b1(26);
    
    BinaryNumber b2("1101");
    BinaryNumber b3 = b1 - b2;
    stringstream str;
    str << b1;


    string name = "Subtraction: B1 retains value";
    string ans = "11010";
    test(name, str.str(), ans);
    str.str("");

    str << b2;
    name = "Subtraction: B2 retains value";
    ans = "1101";
    test(name, str.str(), ans);
    str.str("");

    str << b3;
    name = "Subtraction Operator";
    ans = "1101";
    test(name, str.str(), ans);
}

template<typename Type>
bool test(string name, Type is, Type shouldBe){
    if(is == shouldBe){
        cout << "Passed: " << name << endl;
        return true;
    }
    else{
        cout << name << " was " << is << " should have been " << shouldBe << endl;
    }
    return false;
}

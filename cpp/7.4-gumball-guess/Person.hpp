#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person() : name(""), guess(0) {}
    Person(string name, int guess) : name(name), guess(guess) {}

    bool operator>(const Person& g) const;
    bool operator<(const Person& g) const;
    bool operator>=(const Person& g) const;
    bool operator<=(const Person& g) const;
    bool operator==(const Person& g) const;
    bool operator!=(const Person& g) const;

    int guess;
    friend ostream& operator<<(ostream& out, const Person& g);

private:
    string name;
};

bool Person::operator>(const Person& g) const {
    return guess > g.guess;
}

bool Person::operator<(const Person& g) const {
    return guess < g.guess;
}

bool Person::operator>=(const Person& g) const {
    return guess >= g.guess;
}

bool Person::operator<=(const Person& g) const {
    return guess <= g.guess;
}

bool Person::operator==(const Person& g) const {
    return guess == g.guess;
}

bool Person::operator!=(const Person& g) const {
    return guess != g.guess;
}

ostream& operator<<(ostream& out, const Person& g) {
    out << g.name << ": " << g.guess;
    return out;
}
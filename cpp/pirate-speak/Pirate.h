#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using std::string;

class Pirate {
  public:
    string translateWord(string);
    string translateSentence(string);
    void addToFile(string, string);
};

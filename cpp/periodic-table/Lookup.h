#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

using std::string, std::vector;

std::vector<std::string> splitStringByComma(const std::string& str) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, ',')) {
        result.push_back(item);
    }

    return result;
}

struct Element {
  string atomicNumber;
  string name;
  string symbol;
  string atomicMass;
};

std::ostream& operator<<(std::ostream& out, const Element& e) {
  out << "Number: " << e.atomicNumber << "\nName: " << e.name << "\nSymbol: " << e.symbol << "\nMass: " << e.atomicMass;
  return out;
}

class Lookup {
  public:
    void setElements();
    vector<Element> getElements();
  private:
   vector<Element> elements; 
};

void Lookup::setElements() {
  std::ifstream fin("elements.csv", std::ios::in); // elements.csv with read
  if (!fin.good()) {
    throw std::runtime_error("error reading elements.csv");
    return;
  }

  while (!fin.eof()) {
    string line;
    while (std::getline(fin, line)) {
      Element newElement;
      vector<string> split = splitStringByComma(line);
      newElement.atomicNumber = split[0];
      newElement.name = split[1];
      newElement.symbol = split[2];
      newElement.atomicMass = split[3];
      elements.push_back(newElement);
    }
  }
}

vector<Element> Lookup::getElements() {
  return elements;
}

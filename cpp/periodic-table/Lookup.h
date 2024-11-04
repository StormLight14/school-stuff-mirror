#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using std::string, std::vector;

struct Element {
  string atomicNumber;
  string name;
  string symbol;
  string atomicMass;
};

class Lookup {
  public:
    void setElements();
  private:
   vector<Element> elements; 
};

void setElements() {
  std::ifstream fin("elements.csv", std::ios::in);
  if (!fin.good()) {
    throw std::runtime_error("error reading elements.csv");
    return;
  }

  while (!fin.eof()) {
    string line;
    while (std::getline(fin, line)) {
      Element newElement;
      
    }
  }
}

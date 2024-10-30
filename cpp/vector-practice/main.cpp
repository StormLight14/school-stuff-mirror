#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<double> values){
 for(int i = 0; i < values.size(); i++){
   cout << values.at(i) << ", ";
 }
 cout << endl;
}


int main() {
     vector<double>values;
    
     for(double i = .5; i < 5; i+= .5)
         values.push_back(i);
        
     values.insert(values.begin() + 6, 9.9);
     displayVector(values);
     cout << "Num Items: " << values.size() << endl;
     cout << "Position 2: " << values[20] << endl;
  }


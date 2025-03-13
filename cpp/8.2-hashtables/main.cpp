#include "ChainedHashtable.h"
#include <iostream>

using namespace std;

int main() {
ChainedHashtable<int>ht(7);
ht.insert(18);
ht.insert(21);
ht.insert(25);
cout << ht << endl;
}
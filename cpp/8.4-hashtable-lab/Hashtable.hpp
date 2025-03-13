#include <iostream>
#include <memory>
#include <cmath>
#include <stdexcept>

using namespace std;

template<typename Type>
struct Bucket {
  Type data;
  bool empty = true;
};

template<typename Type>
class Hashtable;

template<typename Type>
ostream& operator<< (ostream &, Hashtable<Type>&);

template<typename Type>
class Hashtable {
public:
  Hashtable();
  Hashtable(int capacity);
  Hashtable(int capacity, double loadFactorThreshold);
  Hashtable(const Hashtable<Type>& other);
  Hashtable<Type>& operator=(const Hashtable<Type>& other);

  int getSize() const;
  int getCapacity() const;
  double getLoadFactorThreshold() const;
  bool empty() const;
  void insert(const Type value);
  void remove(Type value);
  bool contains(Type value) const;
  static bool isPrime(int num);
  static int nextPrime(int num);
  int indexOf(Type value);
  void clear();

  friend ostream& operator<< <>(ostream &, Hashtable<Type>&);

private:
  int hash(Type value) const;
  int capacity;
  int size;
  double loadFactorThreshold;
  unique_ptr<Bucket<Type>[]> hashtable;
  void resize();
};

template<typename Type>
Hashtable<Type>::Hashtable() : size(0), capacity(17), loadFactorThreshold(0.65), hashtable(make_unique<Bucket<Type>[]>(capacity)) {}

template<typename Type>
Hashtable<Type>::Hashtable(int capacity) : size(0), capacity(capacity), loadFactorThreshold(0.65), hashtable(make_unique<Bucket<Type>[]>(capacity)) {}

template<typename Type>
Hashtable<Type>::Hashtable(int capacity, double loadFactorThreshold) : size(0), capacity(capacity), loadFactorThreshold(loadFactorThreshold), hashtable(make_unique<Bucket<Type>[]>(capacity)) {}

template<typename Type>
Hashtable<Type>::Hashtable(const Hashtable<Type>& other) : size(other.size), capacity(other.capacity), loadFactorThreshold(other.loadFactorThreshold), hashtable(make_unique<Bucket<Type>[]>(capacity)) {
  for (int i = 0; i < capacity; ++i) {
    hashtable[i] = other.hashtable[i];
  }
}

template<typename Type>
Hashtable<Type>& Hashtable<Type>::operator=(const Hashtable<Type>& other) {
  if (this != &other) {
    size = other.size;
    capacity = other.capacity;
    auto new_hashtable = make_unique<Bucket<Type>[]>(capacity);
    for (int i = 0; i < capacity; ++i) {
      new_hashtable[i] = other.hashtable[i];
    }
    hashtable = move(new_hashtable);
  }
  
  return *this;
}

template<typename Type>
int Hashtable<Type>::hash(Type value) const {
  int num = static_cast<int>(value) % capacity;
  //cout << value << " % " << capacity << " = " << num << "\n";
  return num;
}

template<typename Type>
void Hashtable<Type>::resize() {
    int newCapacity = capacity * 2;
    newCapacity = nextPrime(newCapacity);
    unique_ptr<Bucket<Type>[]> newHashtable = make_unique<Bucket<Type>[]>(newCapacity);

    int oldCapacity = capacity;
    capacity = newCapacity;
    size = 0;

    for (int i = 0; i < oldCapacity; ++i) {
        if (!hashtable[i].empty) {
            Type value = hashtable[i].data;
            int index = hash(value);
            int j = 0;
            while (!newHashtable[index].empty) {
                j++;
                index = (index + j * j) % capacity;
            }
            newHashtable[index] = {value, false};  // insert stuff into new table
            size++;
        }
    }

    // move the new table into original hashtable
    hashtable = move(newHashtable);
}

template<typename Type>
int Hashtable<Type>::getSize() const {
  return size;
}

template<typename Type>
int Hashtable<Type>::getCapacity() const {
  return capacity;
}

template<typename Type>
double Hashtable<Type>::getLoadFactorThreshold() const {
  return loadFactorThreshold;
}

template<typename Type>
bool Hashtable<Type>::empty() const {
  return size == 0;
}

template<typename Type>
void Hashtable<Type>::insert(Type value) {
    if (static_cast<double>(size + 1) / capacity > loadFactorThreshold) {
        resize();
    }

    int index = hash(value);
    int i = 0;

    while (!hashtable[index].empty) {
        // don't have duplicates
        if (hashtable[index].data == value) {
            return;
        }
        i++;
        //cout << hash(value) << " + " << i*i << " = ";
        index = (hash(value) + i * i) % capacity;
        //cout << index << "\n";
    }

    hashtable[index] = {value, false};
    size++;
}


template<typename Type>
void Hashtable<Type>::remove(Type value) {
  int index = hash(value);
  int i = 0;
  while (hashtable[index].empty || hashtable[index].data != value) {
    i += 1;
    index = (hash(value) + i * i) % capacity;
    if (index == hash(value)) {
      return;
    }
  }

  hashtable[index] = {Type(), true};
  size--;
}

template<typename Type>
bool Hashtable<Type>::contains(Type value) const {
  int index = hash(value);
  int i = 0;
  while (hashtable[index].empty || hashtable[index].data != value) {
    i += 1;
    index = (hash(value) + i * i) % capacity;
    if (index == hash(value)) {
      return false;
    }
  }
  return true;
}

template<typename Type>
void Hashtable<Type>::clear() {
  size = 0;
  for (int i = 0; i < capacity; ++i) {
    hashtable[i] = {Type(), true};
  }
}

template<typename Type>
bool Hashtable<Type>::isPrime(int num) {
  int primes[308] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017
  };


  for (int i=0; i<307; i++) {
    if (primes[i] == num) {
      return true;
    }
  }

  return false;
}

template<typename Type>
int Hashtable<Type>::nextPrime(int num) {
  int primes[308] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017
  };


  for (int i=0; i<307; i++) {
    if (primes[i] > num) {
      return primes[i];
    }
  }

  return primes[307];
}

template<typename Type>
int Hashtable<Type>::indexOf(Type value) {
  int index = hash(value);
  int i = 0;

  while (!hashtable[index].empty) {
    if (hashtable[index].data == value) {
      return index;
    }
    
    i++;
    index = (hash(value) + i * i) % capacity;

    if (index == hash(value)) {
      return -1;
    }
  }

  return -1; 
}


template<typename Type>
ostream& operator<< (ostream& out, Hashtable<Type>& h) {
  out << "\nCapacity: " << h.capacity << "\n";
  for (int i = 0; i < h.capacity; i++) {
    if (!h.hashtable[i].empty) {
      out << i << ": " << h.hashtable[i].data << endl;
    }
  }

  return out;
}

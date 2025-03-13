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
    Hashtable(const Hashtable<Type>& other);
    Hashtable<Type>& operator=(const Hashtable<Type>& other);

    int getSize() const;
    int getCapacity() const;
    bool empty() const;
    void insert(const Type value);
    void remove(Type value);
    bool contains(Type value) const;
    void clear();

    friend ostream& operator<< <>(ostream &, Hashtable<Type>&);

private:
    int hash(Type value) const;
    int capacity;
    int size;
    unique_ptr<Bucket<Type>[]> hashtable;
};

template<typename Type>
Hashtable<Type>::Hashtable() : size(0), capacity(17), hashtable(make_unique<Bucket<Type>[]>(capacity)) {}

template<typename Type>
Hashtable<Type>::Hashtable(int capacity) : size(0), capacity(capacity), hashtable(make_unique<Bucket<Type>[]>(capacity)) {}

template<typename Type>
Hashtable<Type>::Hashtable(const Hashtable<Type>& other) : size(other.size), capacity(other.capacity), hashtable(make_unique<Bucket<Type>[]>(capacity)) {
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
    return static_cast<int>(value) % capacity; // compiler complained abt the fmod thing
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
bool Hashtable<Type>::empty() const {
    return size == 0;
}

template<typename Type>
void Hashtable<Type>::insert(Type value) {
    if (size >= capacity) {
        throw runtime_error("Hashtable is Full");
    }

    int index = hash(value);
    while (!hashtable[index].empty) {
        index = (index + 1) % capacity;
    }

    hashtable[index] = {value, false};
    size++;
}

template<typename Type>
void Hashtable<Type>::remove(Type value) {
    int index = hash(value);
    while (hashtable[index].empty || hashtable[index].data != value) {
        index = (index + 1) % capacity;
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
    while (hashtable[index].empty || hashtable[index].data != value) {
        index = (index + 1) % capacity;
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
ostream& operator<< (ostream & out, Hashtable<Type>& h) {
    out << "\nCapacity: " << h.capacity << "\n";
    for (int i = 0; i < h.capacity; i++) {
        if (!h.hashtable[i].empty) {
            out << i << ": " << h.hashtable[i].data << endl;
        }
    }
    return out;
}

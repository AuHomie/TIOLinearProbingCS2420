#ifndef LINEARHASHTABLE_H
#define LINEARHASHTABLE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

template <class T>
class LinearHashtable;

template<class T>
std::ostream& operator<<(std::ostream& out, const LinearHashtable<T>& t); 

template <class T>
class LinearHashtable {

    public:

        LinearHashtable(int capacity = 499);//Constructor, that initializes the hash table.  It initializes the array for storing the data to size capacity.
        ~LinearHashtable(); //Deallocates memory used from the array pointer.
        void add(T item);  //Adds an item to the array, if a collision occurs, it will try the next position until it finds an empty position.  If the hash table is at capacity then std::throw runtime_error("Table is full");
        bool contains(T item); //Determines if an item is in the hash table
        bool remove(T item); //Removes the item from the hash table
        bool full(); //Determines if the hash table has reached capacity
        int size(); //Determines the max capacity of the hash table
        bool empty(); //returns true if the hash table is empty
        T &operator[] (int ndx); //returns the value at position ndx
        friend std::ostream& operator<< <>(std::ostream& out, const LinearHashtable<T> & t); //Allows the user to output the hash table


    private:
     int capacity;
     int count;
     T* htable;

};

template<class T>
LinearHashtable<T>::LinearHashtable(int capacity){
    this->capacity = capacity;
    this->count = 0;
    htable = new T[capacity](); 
};

template<class T>
LinearHashtable<T>::~LinearHashtable(){
    delete[] htable;
}; 

template<class T>
void LinearHashtable<T>::add(T item) {
    if (full()) {
        throw std::runtime_error("Table is full");
    }

    int key = item % capacity;
    while (htable[key] != 0) { 
        key = (key + 1) % capacity;
    }
    htable[key] = item;
    count++;
}

template<class T>
bool LinearHashtable<T>::empty() {
    return count == 0;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const LinearHashtable<T>& t) {
    for (int i = 0; i < t.capacity; ++i) {
        out << "[" << i << "]: " << t.htable[i] << "\n";
    }
    return out;
}

template<class T>
bool LinearHashtable<T>::full(){
    return count == capacity; 
}

template<class T> 
int LinearHashtable<T>::size(){
    return count;
}

template<class T>
T& LinearHashtable<T>::operator[](int ndx) {
    return htable[ndx];
}

template<class T>
bool LinearHashtable<T>::contains(T item){
    int key = item % capacity;
    for(int i = 0; i < capacity; i++)
    {
        if (htable[key] == item) {
            return true;
        }
        if (htable[key] == 0) { 
            return false;
        }
        key = (key + 1) % capacity; 
    }
    return false; 
}

template<class T>
bool LinearHashtable<T>::remove(T item){
    int key = item % capacity;
    for(int i = 0; i < capacity; i++)
    {
        if (htable[key] == item) {
            htable[key] = 0; 
            count--;
            return true; 
        }
        if (htable[key] == 0) { 
            return false;
        }
        key = (key + 1) % capacity; 
    }
    return false; }

#endif // LINEARHASHTABLE_H


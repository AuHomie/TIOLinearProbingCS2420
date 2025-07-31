#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include <iostream>
#include <iomanip>


template <class Type>
struct Node {
    Type info; // The data stored in the node
    Node<Type>* link; // Pointer to the next node in the chain
};

template <class Type>
class LinearHashtable;

template<class Type>
std::ostream& operator<< <>(std::ostream& out, const LinearHashtable<Type>& t); //Allows the user to output the hash table

template <class Type>
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
        Type &operator[] (int ndx); //returns the value at position ndx
        friend ostream& operator<< <>(ostream& out, const LinearHashtable<T>& t); //Allows the user to output the hash table


    private:
     int capacity;
     int ndx;
     Node<Type>** htable;

};
template<class Type>
LinearHashtable<Type>::
friend ostream& operator<< <>(ostream& out, const LinearHashtable<T>& t); //Allows the user to output the hash table

    
/*
template<class Type>
LinearHashtable<Type>::LinearHashtable(int capacity = 499);//Constructor, that initializes the hash table.  It initializes the array for storing the data to size capacity.


template<class Type>
LinearHashtable<Type>::~LinearHashtable(); //Deallocates memory used from the array pointer.


template<class Type>
void LinearHashtable<Type>::add(TLinearHashtable<Type>:: item);  //Adds an item to the array, if a collision occurs, it will try the next position until it finds an empty position.  If the hash table is at capacity then std::throw runtime_error("Table is full");


template<class Type>
bool LinearHashtable<Type>::contains(T item); //Determines if an item is in the hash table


template<class Type>
boo LinearHashtable<Type>::remove(T item); //Removes the item from the hash table


template<class Type>
bool LinearHashtable<Type>::full(); //Determines if the hash table has reached capacity


template<class Type>
int LinearHashtable<Type>::size(); //Determines the max capacity of the hash table


template<class Type>
bool LinearHashtable<Type>::empty(); //returns true if the hash table is empty


template<class Type>
Type LinearHashtable<Type>::&operator[] (int ndx); //returns the value at position ndx


template<class Type>
friend LinearHashtable<Type>::ostream& operator<< <>(ostream& out, const LinearHashtable<T>& t); //Allows the user to output the hash table
*/
#endif //CHSINEDHASHTABLE_H

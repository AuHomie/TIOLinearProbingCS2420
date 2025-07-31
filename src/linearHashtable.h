/*
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
*/

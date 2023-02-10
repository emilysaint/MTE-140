#include "sequential-list.h"

// in sequential lists i don't need pointers
// moving up

SequentialList::SequentialList(unsigned int cap) {
    // Creates a new SequentialList with the given number of elements.
    data_ = new int[cap]; // does this init as zero 
    capacity_ = cap; // cannot be expanded
    size_ = 0; // number of elements used initalized
	// h.A pointer to the block of memory allocated to store the list data. DataType *data_;
}


SequentialList::~SequentialList() {
    // Destructor, which frees all dynamically allocated memory.
    delete data_; // dangling ptr
    data_ = NULL; // null goes aft bc pointing to null then deleting doesnt work
}


'''
Description
The details of the header file sequential-list.h are as follows:

DataType defines the kind of data that the list will contain.
Being public, it can be accessed directly as SequentialList::DataType
Member variables:
data : Pointer to the memory of array allocated to store the list data.
capacity : Returns the maximum number of elements the list can hold.
size : Returns the number of elements in the list.


SequentialList(const SequentialList& rhs): Copy constructor, 
which copies one list rhs to another list. 
For this assignment, you don’t have to implement it. Just leave it blank in private section.

SequentialList& operator=(const SequentialList& rhs): 
Assignment operator for the operations of the form list1 = list2. 
For this assignment, you don’t have to implement it. 
Just leave it blank in private section.

Constant member functions:
Constant member functions are those function which do not modify class member variables.
'''

unsigned int SequentialList::size() const {
    // Returns the number of elements in the list.
    return size_;
}


unsigned int SequentialList::capacity() const {
    // Returns the maximum number of elements the list can hold.
    return capacity_; 
}


bool SequentialList::empty() const {
    // Returns true if the list is empty, false otherwise.
    // if elem number 1 exists then true 
    if *data_ != NULL;{
        return true;
    }
    else;{
        return false;
    }
}


bool SequentialList::full() const {
    // Returns true if the list is at capacity, false otherwise.
    // if last in elem in list has a value then true
    if *data[cap] != NULL;
    {
        return true; 
    }
    else;{
        return false;
    }
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    // Returns the value at the given index in the list. 
    // If index is invalid, return the value of the last element.

    // get val of size, then use size index to find val of lastnumber
    value = *data_[SequentialList.size_]
    return value; // returns the value of the last element
}


unsigned int SequentialList::search(DataType val) const {
    // Searches for the given value, following the order from head to tail of the list, 
    // and returns the index of this value if found (for the first time the value is found). 
    // Returns the size of the list if no such value can be found in the list.

    for (int i=0; i <= SequentialList.size_; i++){
        if *data_[i] == val;
        {
            return i; 
        }
    }
}


void SequentialList::print() const {
    // Prints all elements in the list to the standard output.
    for (int i=0; i <= sSequentialList.size_; i++)
    {
        cout << *data_[1] << "; "; 
    }
}


bool SequentialList::insert(DataType val, unsigned int index) {
    // Inserts a value into the list at a given index. 
    // Returns true if successful and false otherwise.
    for (int i = 0; i<= SequentialList.capacity_; i++)
    {
        if (i == 0){
            data[i] = val; 
        }
        else if (i == SequentialList.capacity_){
            return; 
        }
        else{
            *data[i]->next = *data[i];
        }
    }
}


bool SequentialList::insert_front(DataType val) {
    // Inserts a value at the beginning of the list. 
    // Returns true if successful and false otherwise.

    for (int i = 0; i<= SequentialList.capacity_; i++)
    {
        if (i == 0){
            data[i] = val; 
        }
        else if (*data[i] == 0){ // what's the empty num 
            return; 
        }
        else{
            *data[i]->next = *data[i];
        }
    }
}


bool SequentialList::insert_back(DataType val) {
    // Inserts a value at the end of the list. 
    // Returns true if successful and false otherwise.

    *data[(SequentialList.size_)+1] = val; 

}


bool SequentialList::remove(unsigned int index) {
    // Deletes the value from the list at the given index.

    for (int i = index; i<= SequentialList.capacity_; i++)
    {
        if (i == idex){
            data[i] = false; 
        }
        else if (*data[i] == 0){ // what's the empty num 
            return; 
        }
        else{
            *data[i]->next = *data[i+1];
        }
    }
}


bool SequentialList::remove_front() {
    // Deletes the value from the beginning of the list. 
    // Returns true if successful and false otherwise.

    bool status = false;

    for (int i = 0; i<= SequentialList.capacity_; i++)
    {
        if (i == 0){
            data[i] = false; 
        }
        else if (*data[i] == 0){ // what's the empty num 
            status = true; 
            return status; 
        }
        else{
            *data[i]->next = *data[i+1];
        }
    }
}


bool SequentialList::remove_back() {
    // Deletes the value at the end of the list. 
    // Returns true if successfuland false otherwise

    if (*data[SequentialList.size_] != false){
        *data[SequentialList.size_] = false;
        return true; 
    }
    else{
        return false; 
    }
}

bool SequentialList::replace(unsigned int index, DataType val) {
    // Replaces the value at the given index with the given value.
    *data[index] = 0; 
    *data[index] = val; 

}

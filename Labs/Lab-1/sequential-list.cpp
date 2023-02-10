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
    if (size_ == 0){
        return true;
    }
    else{
        return false;
    }
}


bool SequentialList::full() const {
    // Returns true if the list is at capacity, false otherwise.
    // if last in elem in list has a value then true
    if (size_ == capacity_){
        return true; 
    }
    else{
        return false;
    }
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    // Returns the value at the given index in the list. 
    // If index is invalid, return the value of the last element.

    if (index <= size_ and index >= 0){
        return data_[index]; 
    }
    else{
        return data_[size_-1];
    }
}


unsigned int SequentialList::search(DataType val) const {
    // Searches for the given value, following the order from head to tail of the list, 
    // and returns the index of this value if found (for the first time the value is found). 
    // Returns the size of the list if no such value can be found in the list.

    for (int i=0; i <= size_; i++){
        if (data_[i] == val){
            return i; 
        }
    }
    return size_; // if no return then return this
}


void SequentialList::print() const {
    // Prints all elements in the list to the standard output.
    // anything past size to capacity, is it zeros or trash memory
    for (int i=0; i < size_; i++)
    {
        cout << data_[i] << "; "; 
    }
}


bool SequentialList::insert(DataType val, unsigned int index) {
    // Inserts a value into the list at a given index. 
    // Returns true if successful and false otherwise.

    if (index < 0){
        return false; 
    }
    else if (size_ == capacity_){
        return false; 
    }
    else if (index <= size_){
        for (int i = (size_ - 1); i >= index; i--)
        {
            data_[i+1] = data_[i]; 
        }

        data_[index] = val;
        size_ ++; // it is changing the feild in the same instance that the mth is running on. If a is my SequentialList instance, then i can call in main a.size_ = some int
        return true; 
    }
    return false;
}


bool SequentialList::insert_front(DataType val) {
    // Inserts a value at the beginning of the list. 
    // Returns true if successful and false otherwise.

    return insert(val, 0);

}


bool SequentialList::insert_back(DataType val) {
    // Inserts a value at the end of the list. 
    // Returns true if successful and false otherwise.
    
    return insert(val, size_);

}


bool SequentialList::remove(unsigned int index) {
    // Deletes the value from the list at the given index.

    if (index < 0){
        return false; 
    }
    else if (size_ == 0){
        return false; // cap = 5 and size = 5, means that list is full
    }
    else if (index < size_){
        // remove element at list
        // shift elems down
        for (int i = index, i < (size_-1), i++){
            data[i] = data[i+1]; 
        }
        size_ --; // c++ does update size automatically, size is a car holding an int val
        return true; 
    }
    return false;
}
}


bool SequentialList::remove_front() {
    // Deletes the value from the beginning of the list. 
    // Returns true if successful and false otherwise.

    return remove(0); 
    // instance.remove(...) already inside the list, vice versa with main

}


bool SequentialList::remove_back() {
    // Deletes the value at the end of the list. 
    // Returns true if successfuland false otherwise

    return remove(size_-1); // no elem at size, parameter of index
}

bool SequentialList::replace(unsigned int index, DataType val) {
    // Replaces the value at the given index with the given value.
    if (index < size_) and (index >= 0){
        data[index] = val;
        return true; 
    } 
    return false; 

}

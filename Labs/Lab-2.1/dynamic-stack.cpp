#include "dynamic-stack.h"

// You need to use dynamically re-sizable array to implement it.
// (Note that “dynamic” here means that the size of the array can change dynamically.
// It is different from the meaning of “dynamic” in dynamic memory allocation.)

// https://www.scaler.com/topics/stack-in-c/
// https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/ 

// Maximum size of Stack
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

// general code
DynamicStack::DynamicStack() {
    int top_; // init top
}

DynamicStack::DynamicStack(unsigned int capacity){
    items_ = new int[EMPTY_STACK];
    capacity_ = capacity; 
    init_capacity_ = capacity;
    size_ = 0; 
}

/* 
used for test
DynamicStack::DynamicStack() :
        items_(new StackItem[16]),
        capacity_(16),
        size_(0),
        init_capacity_(16) {}

DynamicStack::DynamicStack(unsigned int capacity) :
        items_(new StackItem[capacity]),
        capacity_(capacity),
        size_(0),
        init_capacity_(capacity) {}
*/

DynamicStack::~DynamicStack() {
    delete[] items_;
    items_ = nullptr;
}

// Returns the number of items in the stack
unsigned int DynamicStack::size() const {
    return size_;
}

// Returns true if the stack is empty and false otherwise.
bool DynamicStack::empty() const {
    if(size_ < 1){
        return true;
    }
    return false;
}

// ???? item at top?
DynamicStack::StackItem DynamicStack::peek() const {
    // Empty case
    if (size_ <= 0){
        return false; 
    }
    else{
        return items_[size_-1]; 
    }
}

// Takes as an argument a StackItem value. 
// If the stack is not full, the value is pushed onto the stack. 
// Otherwise, the capacity of the stack is doubled, and the item is then pushed onto the resized stack.
void DynamicStack::push(StackItem value) {
    // When array is not at capacity 
    if (capacity_ != 0){
        // When array is full
        if (size_ == capacity_){
            // Create a new bigger stack
            auto *biggerStack = new StackItem[capacity_ *= 2];

            // Transfer all data
            for (int i = 0; i < size_; i++){
                biggerStack[i] = items_[i];
            }
            delete[] items_;
            items_ = biggerStack; 
        }
    }
    // When array is not full, push new value in stack
    // Increment top and add value
    items_[size++] = value;
    }
}

// Removes and returns the top item from the stack as long as the stack is not empty. 
// If the number of items remaining in the stack after popping is less than or 
//      equal to one quarter of the capacity of the array, then the array is halved. 
// However, if the new halved capacity is less than the initial capacity, then no resizing takes place. 
// Finally, If the stack is empty before the pop, the EMPTY STACK constant is returned.
DynamicStack::StackItem DynamicStack::pop() {
    // Stack is empty
    if (size_ <= 0) {
        return EMPTY_STACK;
    }
    // When not empty remove top item 
    else {
        // When size is <= cap/4, half the array size
        if ((size_ <= (capacity_/4)) && (init_capacity_<(capacity_ / 2))){ 
            // Check size if half, create new array and resize
            auto *resizedStack = new StackItem[capacity_ / 2];

            // Move items over
            for (int i = 0; i < size_; i++){
                resizedStack[i] = items_[i]; 
            }
            delete[] items_;
            items_ = resizedStack;
        }
        // store value of stack[top] and decrement top
        return items_[size_--];
    }
}

// Prints the stack items sequentially and in order, from the top to the bottom of the stack. 
// (Note: it is mainly used to help you visualize the data. It will not be used in any test cases for grading.)
// https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/
void DynamicStack::print() const {

    // if empty, if incorrect size
    if (items_.empty()){
        return false; 
    }
    else{
        // Peek
        int x = items_.peek(); // new?
        // Print out data
        std::cout << x << " "<<std::endl;
        // Remove top element
        items_.pop();
        // Function call back for next item in stack 
        items_.push(x);
    }
}


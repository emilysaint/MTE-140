#include "dynamic-stack.h"

// You need to use dynamically re-sizable array to implement it.
// (Note that “dynamic” here means that the size of the array can change dynamically.
// It is different from the meaning of “dynamic” in dynamic memory allocation.)

// https://www.scaler.com/topics/stack-in-c/
// https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/ 

// Maximum size of Stack
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    int top_;
}

DynamicStack::DynamicStack(unsigned int capacity){
    data_ = new int[EMPTY_STACK];
    capacity_ = capacity; 
    size_ = 0; 
}

DynamicStack::~DynamicStack() {
    for (int i=0;i<data_.size();++i){
        delete data_[i];
    }
    data_ = nullptr;
}

// Returns the number of items in the stack
unsigned int DynamicStack::size() const {
    return size_;
}

// Returns true if the stack is empty and false otherwise.
bool DynamicStack::empty() const {
    if(top_ < 1){
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
        return stack[top_]; 
    }
}

// Takes as an argument a StackItem value. 
// If the stack is not full, the value is pushed onto the stack. 
// Otherwise, the capacity of the stack is doubled, and the item is then pushed onto the resized stack.
void DynamicStack::push(StackItem value) {
    // Overflow state
    //  if (top_ > EMPTY_STACK-1){

    if (top_ >= capacity_){
        capacity_ *= 2;  
    }
    // When array is not full, push new value in stack
    // Increment top and add value
    data_[++top_] = value; // ? dose it matter ++/++
    }
}

// Removes and returns the top item from the stack as long as the stack is not empty. 
// If the number of items remaining in the stack after popping is less than or 
//      equal to one quarter of the capacity of the array, then the array is halved. 
// However, if the new halved capacity is less than the initial capacity, then no resizing takes place. 
// Finally, If the stack is empty before the pop, the EMPTY STACK constant is returned.
DynamicStack::StackItem DynamicStack::pop() {
    // Stack is empty
    if (top < 0) {
        return EMPTY_STACK;
    }
    // When not empty remove top item 
    else {
        int x = data_[top--]; // store value of stack[top] and decrement top   // ?????new?

        // When size is <= cap/4, half the array size
        if (size_ <= (capacity_/4)){ 

            // Check size if it were halfed (resized)
            int new_capacity_ = capacity_ / 2;

            // When new cap is < initial capacity do not resize
            if (new_capacity_ < capacity){ // ?????does cap work here 
                break;
            }
            // Resize arra
            capacity_ = new_capacity_;
        }
        // Return top item from stack
        return x;
    }
}

// Prints the stack items sequentially and in order, from the top to the bottom of the stack. 
// (Note: it is mainly used to help you visualize the data. It will not be used in any test cases for grading.)
// https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/
void DynamicStack::print() const {

    // if empty, if incorrect size
    if (data_.empty()){
        return false; 
    }
    else{
        // Peek
        int x = data_.peek(); // new?
        // Print out data
        std::cout << x << " "<<std::endl;
        // Remove top element
        data_.pop();
        // Function call back for next item in stack 
        data.push(x);
    }
}


#include "doubly-linked-list.h"

/* 
1) Node: This is a structure declaration. Node has been declared inside the class as
private, to make sure users do not access nodes directly. Node contains the following
member variables:
    (a) value: Value of the node.
    (b) ext: Address of the next element in the list.
    (c) rev: Address of the previous element in the list.
2) head : Pointer to the first node of the list.
3) tail : Pointer to the last node of the list.
4) size : Number of elements (nodes) in the list. */
DoublyLinkedList::Node::Node(DataType data) {
    Node data; // is this you
}

// Initializes an empty doubly linked list
DoublyLinkedList::DoublyLinkedList() {
    Node* head_ = NULL; 
    Node* tail_ = NULL; 
    size_ = 0; 
}

// Destructor, which frees all dynamically allocated memory, if any.
DoublyLinkedList::~DoublyLinkedList() {
    delete head_; 
    delete tail_;
    head_ = NULL; 
    tail_ = NULL; 
}  

/*
DoublyLinkedList(const DoublyLinkedList& rhs): 
Copy constructor, which copies one list rhs to another list. 
For this assignment, you don’t have to implement it. 
Just leave it blank in private section.
*/

/*
DoublyLinkedList& operator=(const DoublyLinkedList& rhs):
Assignment operator for the operations of the form list1 = list2. 
For this assignment, you don’t have to implement it. 
Just leave it blank in private section.
*/

// Returns the number of elements nodes in the list.
unsigned int DoublyLinkedList::size() const {
    return size_;
}

/* Returns the maximum number of elements the list can hold. 
In linked lists, the capacity is more about an abstract concept. 
Programmers can set this capacity, although the data structure does not have a built in capacity like array’s capacity.
*/
unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY; 
}

// Returns true if the list is empty, false otherwise.
bool DoublyLinkedList::empty() const {
    if (size_ == 0){
        return true; 
    }
    return false;
}

// Returns true if the list is at capacity, false otherwise.
bool DoublyLinkedList::full() const {
    if (size_== CAPACITY){
        return true; 
    }
    return false; 

}

// Returns the value at the given index in the list. 
// If index is invalid, return the value of the last element (the tail node).
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    // if (index < size_ && index >= 0){
    //     return *head_.next[index]; 
    // } 

    // return (*head_).next[index]; 
    //     size ++; 
    //     current = *head_.next; 
    // } 
    // return count; 

    if (index < size_ and index >= 0){
        Node* current = head_;  
        for (int i = 0; i <= index; i++){
            if (1 != index){
                current = head_->next; 
            }
        }
    }
    else{
        Node* current = head_;
        Node* following = current->next_; 
        while (following !== NULL){
            current = following; 
            following = following->next; 
        }
        return *current; 
    }
}  

/*
Searches for the given value, following the order from head to tail of the list, 
and returns the index of this value if found (for the first time the value is found). 
Returns the size of the list if no such value can be found in the list.
*/
unsigned int DoublyLinkedList::search(DataType value) const {
    Node* current = head_; // already derefferenced? 
    for (int i=0; i<size_; i++){
        if (current == value){
            return i; 
        }
        current = current->next; 
    }
    return size_; 
}

// Prints all elements in the list to the standard output.
void DoublyLinkedList::print() const {
    Node* current = head_;
    for (int i=0, i<size_ ; i++){
        std::cout<< current << "; "; 
        current = current->next; 
    }
    std::cout<<std::endl; 

}

/*
Returns a pointer to the node at index. Implementing this function is optional. 
You may use it to help you in select, insert, remove, and replace. 
However, without it, you can also write code to iterate within each of the functions.
*/
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    Node current = head_;
    int i = 0; 
    while (i<index){
        current = current->next; 
    }
    return current; 
}

// Inserts a value into the list at a given index. 
// Returns true if successful and false otherwise.
bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (index <0){
        return false; 
    }
    else if (index == CAPACITY){
        return false; 
    }
    else (if index <= size_){
        Node current = head_;  
        for (int i = 0; i<index; i++){
            current = current->next; 
        }
        // insert new node, data, and next node
        Node previous = current; 
        Node new_node = new Node;
        Node new_node.prev = previous; 
        new_node.next = previous->next->next; 
        return true; 
    }
    return false; 
}

// Inserts a value at the beginning of the list. 
// Returns true if successful and false otherwise.
bool DoublyLinkedList::insert_front(DataType value) {
    insert(value, 0); 

}

// Inserts a value at the end of the list. 
// Returns true if successful and false otherwise.
bool DoublyLinkedList::insert_back(DataType value) {
    insert(value, size_-1) // should it be size
}

// Deletes the value from the list at the given index.
bool DoublyLinkedList::remove(unsigned int index) {
    if (index < 0){
        return false; 
    }
    else if (size_== 0){
        return false; 
    }
    else (index < size_){
        Node current = head_;  
        for (int i = 0; i<=index; i++){
            current = current->next; 
        }
        // insert new node, data, and next node

        delete current->next;
        current->next = NULL;

        Node previous = current; 
        current.next = previous->next->next; 
        (previous->next).prev = current;  

        return true;
    }
    return false;
}

// Deletes the value from the beginning of the list. 
// Returns true if successful and false otherwise.
bool DoublyLinkedList::remove_front() {
    return remove(0); 

}

// Deletes the value at the end of the list. 
// Returns true if successful and false otherwise.
bool DoublyLinkedList::remove_back() {
    return remove(size_-1); 

}

// Replaces the value at the given index with the given value.
bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if ((index<size_)&& (index>=0)){
        Node* current = head_;
        for (int i=0, i<index-1 ; i++){
            std::cout<< current << "; "; 
            current = current->next; 
        }
        *current = value; 
    }
    return false; 
}

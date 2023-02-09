#include "sequential-list.h"

// in sequential lists i don't need pointers
// moving up

SequentialList::SequentialList(unsigned int cap) {
    // Creates a new SequentialList with the given number of elements.
    data_ = new int[cap];
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
    '''
    if (*head).item != 0/null/false; 

    '''
    return status;
}


bool SequentialList::full() const {
    // Returns true if the list is at capacity, false otherwise.
    // if last in elem in list has a value then true
    if list[cap] != 0/NULL/false;
    {
        return true; 
    }
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    // Returns the value at the given index in the list. 
    // If index is invalid, return the value of the last element.

    // get val of size, then use size index to find val of lastnumber
     return value; // returns the value of the last element
}


unsigned int SequentialList::search(DataType val) const {
    // Searches for the given value, following the order from head to tail of the list, 
    // and returns the index of this value if found (for the first time the value is found). 
    // Returns the size of the list if no such value can be found in the list.

    ''' 
    for (int i=0; i < 5; i++)
    {
        if item[i] == val
        {
            return i; 
        }
    }
    '''

}


void SequentialList::print() const {
    // Prints all elements in the list to the standard output.
    ''' 
    for (int i=0; i < 5; i++)
    {
        cout<<*list[1]<< "; "; 
    }
    '''
}

'''
Non-constant member functions:
These functions can potentially modify member variable of the class.
'''

bool SequentialList::insert(DataType val, unsigned int index) {
    // Inserts a value into the list at a given index. 
    // Returns true if successful and false otherwise.

    '''
    void LinkedList::replace(int position, DataType value) {
    # step 1
        Node *current = head;
        int i = 0;
        while (i < position) {
            if (current->next == nullptr) {
                break; # reach the end
                # if this happens, it means that the position value is larger than it should be
                # by continuing the remaining code in this function,
                # the value in the tail node of the list will be replaced
            }
            current = current->next;
            i++;
        }
        # step 2
        current->data = value;
    }
    '''
}


bool SequentialList::insert_front(DataType val) {
    // Inserts a value at the beginning of the list. 
    // Returns true if successful and false otherwise.

    '''
    void LinkedList::insert(DataType value, int
    position) {
        # step 1. create new node
        Node *newNode = new Node(value);
        # step 2
        if(position == 0){
            if(head == nullptr){
                head = newNode;
                return;
            }
            else{ //2.2 when size > 0
                newNode->next = head;
                head = newNode;
                return;
            }
        }
        # step 3
        Node *previous = head;
        Node *current = head->next;
        int i = 1;
        while (i < position) {
            previous = current;
            current = current->next;
            if (current == nullptr) {
                break; # position value invalid
            }
        i++;
        }
        # step 4
        newNode->next = current;
        previous->next = newNode;
    }
    '''
}


bool SequentialList::insert_back(DataType val) {
    // Inserts a value at the end of the list. 
    // Returns true if successful and false otherwise.
}


bool SequentialList::remove(unsigned int index) {
    // Deletes the value from the list at the given index.

    '''
    void LinkedList::remove(int position) {
        # step 1
        if(position == 0){
            Node *temp = head; # NEED A TEMP VAR OR WHOLE ARRA WILL BE LOST
            head = head->next;
            delete temp;
            temp = nullptr;
            return;
        }
        # step 2
        Node *previous = head;
        Node *current = head->next; # CURRENT IS THE TEMP VAL 
        int i = 1;
        while (i < position) {
            if (current->next == nullptr) {
                break; # position value invalid
            }
            previous = current;
            current = current->next;
            i++;
        }
        # step 3
        previous->next = current->next; // current is pointing to the one we want to delete, reassigning the node somewhere else after current, -> does the defrerencing
        delete current; // DANGLING PTR // juping the current and now 
        current = nullptr; // clean up of the one we dont want
    }
'''
}


bool SequentialList::remove_front() {
    // Deletes the value from the beginning of the list. 
    // Returns true if successful and false otherwise.
}


bool SequentialList::remove_back() {
    // Deletes the value at the end of the list. 
    // Returns true if successfuland false otherwise.
}


bool SequentialList::replace(unsigned int index, DataType val) {
    // Replaces the value at the given index with the given value.
    '''
    void LinkedList::replace(int position, DataType value) {
    # step 1
        Node *current = head;
        int i = 0;
        while (i < position) {
            if (current->next == nullptr) {
                break; # reach the end
                # if this happens, it means that the position value is larger than it should be
                # by continuing the remaining code in this function,
                # the value in the tail node of the list will be replaced
            }
            current = current->next;
            i++;
        }
        # step 2
        current->data = value;
    }
    '''
}

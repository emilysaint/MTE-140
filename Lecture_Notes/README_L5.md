# Lecture 5 - Introduction to Linked Lists
Jan 26, 2023

### To Review
- Memory Space - tom's notes
- Hex to bin - tom's notes

<br>

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Make sure to understand pointers <br> - LRN  |- Lab <br> - start lab|


<br>
<hr>
<br>

## Arrays
![L5_array_stuctures.jpg](Screenshots\L5_array_stuctures.jpg)

<br>

## Abstract Data Types
- ADT is a collection of data items given a name , purpose, and a set of functions (interface) that operates on the data items
- With ADT only necessary information is shown externally to the user while the underlying details are hidded

<br>

## A word on Big O Notation
- grade school multiplication
    - how efficient is this algorithim
    - how many single-didgit operations

    ![L5_bigO.jpg](Screenshots\L5_bigO.jpg)

- Big O notaton
    - describes the completity of your code using algebraic terms
    the running time/number of operations that's independent of hardware, programming language, etc

<br>

## Recalling Arrays
- ordered, homogeneous list of data
    - an array's length cannot be changed once it is created
    - the entire memory space of that size is allocated, even if not all of space is used 
- inserting is costly 
    - logic: seaching all array to find the required position, then shift other elements in array

<br>

## Linked lists
- Idea: let's inc and dec the occipied memory space in a more flexible way
- storing every element in it's **own block of memory**
    - effeciently inserting into the middle or back
- each elem is alloc on the heap or the stack memory? (dyn memory)
- a linked list is good for storing elements in an order
- elements are chained together in a sequence - just like a train

<br>

## Node
- what does each part of a linked list need to store?
    - **elem**
    - something that points to the next element (**A pointer - a node** does that)
- A node: a data structure that contains both data items and a pointer to other nodes in the sequence 

![L5_linked_list_seq.jpg](Screenshots\L5_linked_list_seq.jpg)

<br>

## Node Struct
Often def as a struct for easier access
*Structs is a class that has all members public buy default
```cpp
struct Node{
    int data; 
    Node* next;
}
```
Pointer to a node
- the arrow `defreferences` and `accesses` atributes of a stuct that is referenced by a pointer
```cpp
Node* head = new Node; 
head -> data = 10; 
head -> next = NULL;
```

Train analogy
- Elems are chained in a squence

|train|linked list|
|-----|-----------|
|freight car|node|
|contents in car|data item (ie, int)|
|car link|pointer to next node|
|add car|insert nodes|
|remove car|delete nodes|

<br>

## Linked list
- an ordered sequence of nodes, where a pointer inside each node points to the next node in the list
- linked list structure
    - node
        - elem
        - **pointer** to next elem
    - head note
    - tail node (usually pts to **NULL**)

## Basic operations
- init a list with one node
- add a node to the list
- access the data stored in a node
- remove a node

<br>

## Ex 1 - Linked list structure
```cpp
struct LinkedListNode {
    // defined here
    int data; # assume all elements are ints 
    LinkedListNode *next; # default constructor without parameters
    LinkedListNode(): data(0), hext (NULL) {}; # constructor
    LinkedListNode(int x): data(x), next (NULL) {};
    # ":" is the constructor member initializer list used to
    # initialize the class members data and next for this constructor
};
```
```cpp
int main(){
    LinkedListNode *head = new LinkedListNode(); 
    // (*head).next 
    head->data = 10; 
    head->next = new LinkedListNode(); 
    head->next->data = 3; 
    head->next->next = new LinkedListNoide(6); # equivalent to head->next->next->data = 6
    # Print data in all three nodes
    cout << head->data<<", "; 
    cout << head->next->data<<", ";
    cout << head->next->next->data<<endl;
    return 0;
}
```
Removing a node
```cpp
# Removing first node
Node *temp = NULL; 
temp = head; 
head = head->next; # the second node is now the head node
delete temp;
temp = NULL; 
```
Problem: the previous ex is not proper OOP, since all procedures are in main func
Soln: put each mthd in its own func abd group these mths together in a class

<br>
<hr>
<br>

## Summary

### Abstract Data Types
- ADT is a collection of data items given a name , purpose, and a set of functions (interface) that operates on the data items
- With ADT only necessary information is shown externally to the user while the underlying details are hidded

<br>

### A word on Big O Notation
- grade school multiplication
    - how efficient is this algorithim
    - how many single-didgit operations
- Big O notaton
    - describes the completity of your code using algebraic terms
    the running time/number of operations that's independent of hardware, programming language, etc

<br>

### Recalling Arrays
- ordered, homogeneous list of data
    - an array's length cannot be changed once it is created
    - the entire memory space of that size is allocated, even if not all of space is used 
- inserting is costly 
    - logic: seaching all array to find the required position, then shift other elements in array

<br>

### Linked lists
- Idea: let's inc and dec the occipied memory space in a more flexible way
- storing every element in it's **own block of memory**
    - effeciently inserting into the middle or back
- each elem is alloc on the heap or the stack memory? (dyn memory)
- a linked list is good for storing elements in an order
- elements are chained together in a sequence - just like a train

<br>

### Node
- what does each part of a linked list need to store?
    - **elem**
    - something that points to the next element (**A pointer - a node** does that)
- A node: a data structure that contains both data items and a pointer to other nodes in the sequence 

<br>

### Node Struct
- Often def as a struct for easier access
*Structs is a class that has all members public buy default
 - Pointer to a node
    - the arrow `defreferences` and `accesses` atributes of a stuct that is referenced by a pointer

Train analogy
- Elems are chained in a squence

|train|linked list|
|-----|-----------|
|freight car|node|
|contents in car|data item (ie, int)|
|car link|pointer to next node|
|add car|insert nodes|
|remove car|delete nodes|

<br>

### Linked list
- an ordered sequence of nodes, where a pointer inside each node points to the next node in the list
- linked list structure
    - node
        - elem
        - **pointer** to next elem
    - head note
    - tail node (usually pts to **NULL**)

#### Basic operations
- init a list with one node
- add a node to the list
- access the data stored in a node
- remove a node

#### Ex 1 - Linked list structure
- struct
- int main
- Removing a node
Problem: the previous ex is not proper OOP, since all procedures are in main func
Soln: put each mthd in its own func abd group these mths together in a class

<br>

## To Review
- incapulation
- this
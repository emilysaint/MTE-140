# Lab Assignment #1, Part #2 of 2 (Doubly Linked List Implementation)

Due: 11:59 PM, Friday, February 17, 2023

<br>

Purpose of this lab assignment
In this lab assignment, you will practice your knowledge about linked list by implementing a data type called doubly linked list. The header file `doubly-linked-list.h`, which is explained below, provides the structure of the `DoublyLinkedList class` with declarations of member functions.
Do not modify the signatures of any of these functions. 

<font color="#7f9977">
You need to implement all of the public member functions listed in `doubly-linked-list.cpp`. 
The memory used by this list will change dynamically as nodes are inserted and removed from the list.
</font> 

<br>

## Instructions
- Sign in to GitLab and verify that you have a project set up for your Lab Assignment 1 (lab 1) at https://git.uwaterloo.ca/mte140-2301/a1/WATIAM_ID with the following files.
    - YOUR-WATIAM-ID
    - CMakeLists.txt
    - README.md
    - doubly-linked-list.cpp
    - doubly-linked-list.h
    - sequential-list.cpp
    - sequential-list.h
    - test.cpp

<font color="#7f9977">

For this part of assignment, you only need to **modify** `doubly-linked-list.cpp`. 
You should **design your own test case** and code in test.cpp and **add it to the provided test.cpp** for part 1 (we do not provide test cases any longer as we want you to learn how to do them). It is optional and we will not grade this file. 
</font>

<br>
<hr>
<br>

## Description

The details of the header file doubly-linked-list.h are as follows:
DataType defines the kind of data that the list will contain. Being public, it can be accessed
directly as DoublyLinkedList::DataType.

<br>

### Member variables:
1. `Node` : This is a structure declaration. 
    Node has been declared inside the class as private, to make sure users do not access nodes directly. 

    Node contains the following member variables:
    - `value`: Value of the node.
    - `ext`: Address of the next element in the list.
    - `rev`: Address of the previous element in the list.

2. `head` : Pointer to the first node of the list.
3. `tail` : Pointer to the last node of the list.
4. `size` : Number of elements (nodes) in the list.

<br>

### Constructor and Destructor:
1. `DoublyLinkedList()`: Initializes an empty doubly linked list.
2. `~DoublyLinkedList()`: Destructor, which frees all dynamically allocated memory, if any.
3. `DoublyLinkedList(const DoublyLinkedList& rhs)`: Copy constructor, which copies one list rhs to another list. For this assignment, you don’t have to implement it. Just leave it blank in private section.
4. `DoublyLinkedList& operator=(const DoublyLinkedList& rhs)`: Assignment operator for the operations of the form list1 = list2. For this assignment, you don’t have to implement it
    Just leave it blank in private section.

<br>

### Constant member functions:
Constant member functions are those function which do not modify class member variables.
1. `unsigned int size() const`: Returns the number of elements nodes in the list.
2. `unsigned int capacity() const`: Returns the maximum number of elements the list can hold.
    In linked lists, the capacity is more about an abstract concept. Programmers can set this capacity, although the data structure does not have a built in capacity like array’s capacity.
3. `bool empty() const`: Returns true if the list is empty, false otherwise.
4. `bool full() const`: Returns true if the list is at capacity, false otherwise.
5. `DataType select(unsigned int index) const`: Returns the value at the given index in the list. 
    If index is invalid, return the value of the last element (the tail node).
6. `unsigned int search(DataType val) const`: Searches for the given value, following order from head to tail of the list, and returns the index of this value if found (for the first time the value is found). 
    Returns the size of the list if no such value can be found in the list.
7. `void print() const`: Prints all elements in the list to the standard output.
8. `Node* getNode(unsigned int index) const`: Returns a pointer to the node at index. 
    Implementing this function is optional. You may use it to help you in select, insert, remove, and replace. However, without it, you can also write code to iterate within each of the functions.
    
<br>

### Non-constant member functions:
These functions can potentially modify member variable of the class.
1. `bool insert(DataType val, unsigned int index)`: Inserts a value into the list at a given index. Returns true if successful and false otherwise.
2. `bool insert front(DataType val)`: Inserts a value at the beginning of the list. Returns true if successful and false otherwise.
3. `bool insert back(DataType val)`: Inserts a value at the end of the list. Returns true if successful and false otherwise.
4. `bool remove(unsigned int index)`: Deletes the value from the list at the given index.
5. `bool remove front()`: Deletes the value from the beginning of the list. Returns true if successful and false otherwise.
6. `bool remove back()`: Deletes the value at the end of the list. Returns true if successful and false otherwise.
7. bool replace(unsigned int index, DataType val)`: Replaces the value at the given index with the given value.

<br>
<hr>
<br>

### Notes
- All indexes must start with 0.
- Do not include <bits/stdc++.h>; instead, use individual standard headers such as <string>,
<iostream> when needed.
- In this assignment practice, you can return any value for the case when size is equal to zero.
- In real world practice, this case should cause the program to report an error.

### Marking
- Part 2 counts 50% of Lab Assignment 1 i.e. 50 points in total. We will try different inputs and check your output. We will only test your program with syntactically and semantically correct inputs. Your program:
1. Runs and does not crash during the test: + 10 points.
2. Passes Test Cases: 10 test cases in total, 40 points total (+ 4 points per each test
case).
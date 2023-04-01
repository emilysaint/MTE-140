# Lab Assignment #3, Part #1 of 2 - Binary Search Tree Implementation

<br>

## Purpose of this assignment
In this lab assignment, you will practice your knowledge about tree by implementing a data type called binary search tree. 
The header file `binary-search-tree.h`, which is explained below, provides the structure of the `BinarySearchTree` class with declarations of member functions. 
Do not modify the signatures of any of these functions. 
You need to implement all of the public member functions listed in `binary-search-tree.cpp`. 
Note that the tree does not have to be balanced for this part of the assignment.

<br>

Sign in to GitLab and verify that you have a project set up for your Lab Assignment 3 (lab 3)
## Instruction
at https://git.uwaterloo.ca/mte140-2301/a3/WATIAM_ID with the following files.
- YOUR-WATIAM-ID
- CMakeLists.txt
- README.md
- binary-search-tree.cpp
- binary-search-tree.h
- avl-tree.cpp
- avl-tree.h
- test.cpp

<br>

For this part of assignment, you only need to modify `binary-search-tree.cpp`. 
Do not change any part of the header file (`binary-search-tree.h`).
You will want to design your own test case and code in `test.cpp`. 
It is optional and we will not grade this file. 
We are selectively releasing 4 out of the 8 test cases that will be used to grade you. 
The selective tests are meant to help you design the remaining cases in a similar way. 
We also provide a description for the test cases within the test.cpp file to guide your design in the 8 remaining cases.
You can use the same procedures in the Optional Lab Assignment 0 to pull, edit, build, commit, and push your repo.

<br>

## Description
The details of the header file `binary-search-tree.h` are as follows:
1) `DataType` defines the kind of data that the tree will contain. Being public, it can be
accessed directly as `BinarySearchTree::DataType`.
Member variables:
1) `Node`: This is a structure declaration. Node contains the following member function and variables:
    a) `Node(DataType newval)`: Sets the left and right children to NULL, and initializes val.
    b) `val`: Value of the node.
    c) `left`: Pointer to the left node.
    d) `right`: Pointer to the right node.
    e) `avlBalance`: As introduced in the class, the balance value of each node refers to the absolute value of difference in heights between the left and right subtrees of the node. 
    You may implement updateNodeBalance function to update `avlBalance`.
    It is not necessary for Part 1 about binary search tree, but it may help you when you implement AVL tree in Part 2. 
    Note that there are other methods to implement AVL tree properly without the need to use this variable, so it is optional.
2) `root` : Pointer to the root node of the tree.
3) `size` : Number of nodes in the tree.

<br>

## Member functions:
1) `BinarySearchTree()`: Constructor to initialize an empty tree with no node.
2) `~BinarySearchTree()`: Deallocates the memory space allocated for the binary search tree nodes, if any.
3) `int size() const`: Returns the number of nodes in the tree.
4) `DataType max() const`: Returns the maximum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.
5) `DataType min() const`: Returns the minimum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.
6) `unsigned int depth() const`: Returns the maximum depth of all nodes in the tree.
Since the root node has a depth of 0, a tree with only the root node will have 0 as the return value here. 
You can assume that this function will never be called on an empty tree.
7) `void print() const`: You can print the tree in whatever order you prefer. 
However, methods such as in-order or level-order traversal could be the most useful for debugging.
Note: this function will not be used for grading purposes, so the printing format does not matter.
8) `bool exists(DataType val) const`: Returns true if a node with the value val exists in the tree; otherwise, it returns false.
9) `Node* getRootNode()`: Returns a pointer to the root node.
10) `Node** getRootNodeAddress()`: Returns the address of the root node pointer.
11) `bool insert(DataType val)`: Inserts the value val into the tree as a new node.
Returns false if val already exists in the tree, and true otherwise.
12) `bool remove(DataType val)`: Removes the node with the value `val` from the tree.
Returns true if successful, and false otherwise. 

    Note: when the to-be-removed node has two child nodes, replace the value with the predecessor (rather than successor).
    This implementation will be different from the demo code used in the lecture, which used the successor.

13) `void updateNodeBalance(Node* n)`: Optional. This function is not necessary for
    1) about binary search tree, but it may help you when you implement AVL tree in
    2) Given Node* n that is a pointer pointing to a node in the tree, this function calculates the balance value of Node* n and repeat this for all the ancestors of `Node* n`. 

    Note that there are other methods to implement AVL tree properly without the eed to implement this function, so it is optional.

<br>

## Marking
Part 1 counts 60% of Lab Assignment 3 i.e. 60 points in total. We will try different inputs and check your output. 
We will only test your program with syntactically and semantically correct inputs. 
Your program:
1) Runs and does not crash during the test: + 12 points.
2) Passes Test Cases: 48 points total (8 total test cases) i.e. + 6 points per each test case.
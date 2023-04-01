#include "binary-search-tree.h"
#include <iostream>
using namespace std;

/* This is a structure declaration. 
Node contains the following member function and variables:
a) `Node(DataType newval)`: Sets the left and right children to NULL, and initializes val.
b) `val`: Value of the node.
c) `left`: Pointer to the left node.
d) `right`: Pointer to the right node.
e) `avlBalance`: As introduced in the class, the balance value of each node refers to the absolute value of difference in heights between the left and right subtrees of the node. 
You may implement updateNodeBalance function to update `avlBalance`.
It is not necessary for Part 1 about binary search tree, but it may help you when you implement AVL tree in Part 2. 
Note that there are other methods to implement AVL tree properly without the need to use this variable, so it is optional.*/
BinarySearchTree::Node::Node(DataType newval) {

}

/*2) `root` : Pointer to the root node of the tree.*/
int BinarySearchTree::getNodeDepth(Node* n) const {

}

/*Constructor to initialize an empty tree with no node.*/
BinarySearchTree::BinarySearchTree() {

}

/*Deallocates the memory space allocated for the binary search tree nodes, if any.*/
BinarySearchTree::~BinarySearchTree() {

}

/*Returns the number of nodes in the tree.*/
unsigned int BinarySearchTree::size() const {

}

/*Returns the maximum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.*/
BinarySearchTree::DataType BinarySearchTree::max() const {

}

/*Returns the minimum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.*/
BinarySearchTree::DataType BinarySearchTree::min() const {

}

/*Returns the maximum depth of all nodes in the tree.
Since the root node has a depth of 0, a tree with only the root node will have 0 as the return value here. 
You can assume that this function will never be called on an empty tree.*/
unsigned int BinarySearchTree::depth() const {

}

/*You can print the tree in whatever order you prefer. 
However, methods such as in-order or level-order traversal could be the most useful for debugging.
Note: this function will not be used for grading purposes, so the printing format does not matter.*/
void BinarySearchTree::print() const {

}

/*Returns true if a node with the value val exists in the tree; otherwise, it returns false.*/
bool BinarySearchTree::exists(DataType val) const {

}

/*Returns a pointer to the root node.*/
BinarySearchTree::Node* BinarySearchTree::getRootNode() {

}

/*Returns the address of the root node pointer.*/
BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {

}

/*Inserts the value val into the tree as a new node.
Returns false if val already exists in the tree, and true otherwise.*/
bool BinarySearchTree::insert(DataType val) {

}

/*Removes the node with the value `val` from the tree.
Returns true if successful, and false otherwise. 

Note: when the to-be-removed node has two child nodes, replace the value with the predecessor (rather than successor).
This implementation will be different from the demo code used in the lecture, which used the successor.*/
bool BinarySearchTree::remove(DataType val) {

}

/*OPTIONAL. This function is not necessary for
1) about binary search tree, but it may help you when you implement AVL tree in
2) Given Node* n that is a pointer pointing to a node in the tree, this function calculates the balance value of Node* n and repeat this for all the ancestors of `Node* n`. 

Note that there are other methods to implement AVL tree properly without the eed to implement this function, so it is optional.*/
void updateNodeBalance(Node* n) {

}
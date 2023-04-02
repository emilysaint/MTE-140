#include "binary-search-tree.h"
#include <iostream>
using namespace std;

// https://www.programiz.com/dsa/binary-search-tree
// https://www.softwaretestinghelp.com/binary-search-tree-in-cpp/
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

/* NODE FUNCTION
This is a structure declaration. 
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
    val = newval;        // Value of the node.
    left = nullptr;      // Pointer to the left node.
    right = nullptr;     // Pointer to the right node.
    //int avlBalance;
}

/*`root` : Pointer to the root node of the tree.*/
int BinarySearchTree::getNodeDepth(Node* n) const {
    // This is when empty
    if (n == nullptr){
        return -1;
    }
    // Counting up
    int left_depth = getNodeDepth(n->left);
    int right_depth = getNodeDepth(n->right); 
    else if (left_depth > right_depth){
        return left_depth + 1; 
    }
    else if (left_depth < right_depth){
        return right_depth + 1; 
    }
    else if (left_depth == right_depth){
        return left_depth + 1; 
    }
}

/* CONSTRUCTOR FUNCTION
Constructor to initialize an empty tree with no node.*/
BinarySearchTree::BinarySearchTree() {
    root_ = nullptr; // ? Node* root_ = new Node; 
    size_= 0; 
}


// Destructor of the class BinarySearchTree. It deallocates the memory
// space allocated for the binary search tree.
/*Deallocates the memory space allocated for the binary search tree nodes, if any.*/
BinarySearchTree::~BinarySearchTree() {
    delete Node; 
    Node = nullptr; 
}

/* SIZE FUNCTION
Returns the number of nodes in the tree.*/
unsigned int BinarySearchTree::size() const {
    return size_; 
}

/* MAX FUNCTION
Returns the maximum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.*/
BinarySearchTree::DataType BinarySearchTree::max() const {
    Node* curr = root_; 

    // passing through to the left all the way down
    while (curr->right != nullptr) {
        curr = curr->right; 
    }   
    return curr->val; 
}

/* MIN FUNCTION
Returns the minimum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.*/
BinarySearchTree::DataType BinarySearchTree::min() const {
    Node* curr = root_; 

    // passing to the left all the way down
    while (curr->left != nullptr){
        curr = curr->left; 
    }
    // min value has been found
    return curr->val; 
}

/* DEPTH FUNCTION
Returns the maximum depth of all nodes in the tree.
Since the root node has a depth of 0, a tree with only the root node will have 0 as the return value here. 
You can assume that this function will never be called on an empty tree.*/
unsigned int BinarySearchTree::depth() const {
    return getNodeDepth(root_); 
}

// You can print the tree in whatever order you prefer. However, methods such
// as in-order or level-order traversal could be the most useful for debugging.
/*You can print the tree in whatever order you prefer. 
However, methods such as in-order or level-order traversal could be the most useful for debugging.
Note: this function will not be used for grading purposes, so the printing format does not matter.*/
void BinarySearchTree::print() const {
    printHelper(root_); 
}

void BinarySearchTree::printHelper(Node* n) const {
    if (n == nullptr) {
        return;   
    }
    else {
        printHelper(n->left);
        std::cout << n->data << endl;
        printHelper(n->right);
    }
}

/* EXISTS FUNCTION
Returns true if a node with the value val exists in the tree
Otherwise, it returns false.*/
bool BinarySearchTree::exists(DataType val) const {
    Node* curr = root_; 
    while (curr != nullptr){
        if (curr->val == val){
            return true; 
        }
        else if (curr->val > val){
            // when the current value is less than the value looking for check left
            curr = cur->left;
        }
        else{
            // check right
            curr = curr->right; 
        }
    }
    return false; 
}

/* GET ROOT NODE FUNCTION
Returns a pointer to the root node.*/
BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    return root_; 
}

/* GET ROOT NODE ADDRESS
Returns the address of the root node pointer.*/
BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    return &root_; 
}

// Inserts the value val into the tree. Returns false if val already exists in
// the tree, and true otherwise.
/*Inserts the value val into the tree as a new node.
Returns false if val already exists in the tree, and true otherwise.*/
bool BinarySearchTree::insert(DataType val) {
    Node *newNode = new Node(value);

    if (root_ == nullptr) {
        root_ = newNode;
        return true;
    }

    Node* curr = root_;
    while (curr != nullptr) {
        // Go left
        if (val < curr->data) {
            // there is nothing to the left
            if (!curr->left) {
                curr->left = newNode;
                return true;
            }
            // else go left
            curr = curr->left;
        } 
        // going to the right, data is larger
        else if (data > curr->data) {
            if (!curr->right) {
                curr->right = newNode;
                return true;
            }
            // else keep going right
            curr = curr->right;
        } 
        else {
            // Node with value already exists in the tree
            delete newNode;
            newNode = nullptr; 
            return false;
        }
    }
}

// Removes the node with the value val from the tree. Returns true if successful, and false otherwise.
/*Removes the node with the value `val` from the tree.
Returns true if successful, and false otherwise. 

Note: when the to-be-removed node has two child nodes, replace the value with the predecessor (rather than successor).
This implementation will be different from the demo code used in the lecture, which used the successor.*/
bool BinarySearchTree::remove(DataType val) {
    // nothing there
    if (root_ == nullptr){
        return false; 
    }

    Node* curr = root_; 
    while (curr != nullptr){
        if (val < curr->val){
            curr = curr->left; 
        }
        else if (val > curr->val){
            curr = curr->right; 
        }
        // when value is found
        else{
            Node* found = curr; 
            // passing through to the left all the way down
            Node* parent = curr;
            curr = curr->left; 
            while (curr->right != nullptr) {
                parent = curr;
                curr = curr->right;
            }
            // removing the correct value and replacing it with the highest value on the left side    
            found->val = curr->val; 
            // if there are other left values, bring them with 
            parent->right = curr->left;
            delete curr; 
            curr = nullptr;   
            return true; 
    }
    // wasnt in tree
    return false; 
}

/*OPTIONAL. This function is not necessary for
1) about binary search tree, but it may help you when you implement AVL tree in
2) Given Node* n that is a pointer pointing to a node in the tree, this function calculates the balance value of Node* n and repeat this for all the ancestors of `Node* n`. 

Note that there are other methods to implement AVL tree properly without the eed to implement this function, so it is optional.*/
void updateNodeBalance(Node* n) {

}
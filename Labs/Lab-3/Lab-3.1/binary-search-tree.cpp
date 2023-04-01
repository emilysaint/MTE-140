#include "binary-search-tree.h"
#include <iostream>
using namespace std;

// https://www.programiz.com/dsa/binary-search-tree
// https://www.softwaretestinghelp.com/binary-search-tree-in-cpp/
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

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
    val = newval;        // Value of the node.
    left = nullptr;      // Pointer to the left node.
    right = nullptr;     // Pointer to the right node.
    //int avlBalance;
}

/*2) `root` : Pointer to the root node of the tree.*/
int BinarySearchTree::getNodeDepth(Node* n) const {
    if (n == nullptr){
        return -1;
    }
    if (n == root_){
        return depth;
    }
    int left_depth = getNodeDepthHelper(n->left, depth + 1, root_);
    if (left_depth == -1){
        return getNodeDepthHelper(n->right, depth + 1, root_);
    }
    return left_depth;
}

// Default constructor to initialize the root.
/*Constructor to initialize an empty tree with no node.*/
BinarySearchTree::BinarySearchTree() {
    Node* root_ = new Node; 
    size_= 0; 
}


// Destructor of the class BinarySearchTree. It deallocates the memory
// space allocated for the binary search tree.
/*Deallocates the memory space allocated for the binary search tree nodes, if any.*/
BinarySearchTree::~BinarySearchTree() {
    delete Node; 
    Node = nullptr; 
}

// Returns the number of nodes in the tree.
/*Returns the number of nodes in the tree.*/
unsigned int BinarySearchTree::size() const {
    return size_; 
}

// Returns the maximum value of a node in the tree. You can assume that
// this function will never be called on an empty tree.
/*Returns the maximum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.*/
BinarySearchTree::DataType BinarySearchTree::max() const {
    root_ = getRootNode();
    if (root_ == nullptr) {
        // return INT_MIN;
        return false;
    }
    int max_left = maxHelper(root_->left);
    int max_right = maxHelper(root_->right);
    return std::max(root_->data, std::max(max_left, max_right));
    }
}

// Returns the minimum value of a node in the tree. You can assume that
// this function will never be called on an empty tree.
/*Returns the minimum value of a node in the tree among all the nodes. 
You can assume that this function will never be called on an empty tree.*/
BinarySearchTree::DataType BinarySearchTree::min() const {
    root_ = getRootNode();
    if (root_ == nullptr) {
        return INT_MAX;
    }
    int min_left = minHelper(root_->left);
    int min_right = minHelper(root_->right);
    return std::min(root_->data, std::min(min_left, min_right));
}

// Returns the maximum depth of the tree. A tree with only the root node has a depth of 0. 
// You can assume that this function will never be called on anempty tree.
/*Returns the maximum depth of all nodes in the tree.
Since the root node has a depth of 0, a tree with only the root node will have 0 as the return value here. 
You can assume that this function will never be called on an empty tree.*/
unsigned int BinarySearchTree::depth() const {
    root_ = getRootNode();
    if (root_ == nullptr) {
        return false;
    }
    int depth_left = depthHelper(root_->left);
    int depth_right = depthHelper(root_->right);
    return std::max(depth_left, depth_right) + 1;
    }
}

// You can print the tree in whatever order you prefer. However, methods such
// as in-order or level-order traversal could be the most useful for debugging.
/*You can print the tree in whatever order you prefer. 
However, methods such as in-order or level-order traversal could be the most useful for debugging.
Note: this function will not be used for grading purposes, so the printing format does not matter.*/
void BinarySearchTree::print() const {
    root_ = getRootNode();
    if (root_ == NULL) {
        return false;
    }
    Inorder(root_->left);
    std::cout << root_->data << endl;
    Inorder(root_->right);
}


// Returns true if a node with the value val exists in the tree; otherwise, it returns false.
/*Returns true if a node with the value val exists in the tree; otherwise, it returns false.*/
bool BinarySearchTree::exists(DataType val) const {
    root_ = getRootNode();
    if(root_ == NULL || root_->data == val){
        return root_;
    }
    else if(root_->key < val){
        getRootNodeAddress(root_->left,val);
    }
    else (root_->key > val){
        getRootNodeAddress(root_->right,val);
    }
}


// Returns a pointer to the root node
/*Returns a pointer to the root node.*/
BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    return root_; 
}

// Returns the root node pointer address
/*Returns the address of the root node pointer.*/
BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    return &root_; 
}

// Inserts the value val into the tree. Returns false if val already exists in
// the tree, and true otherwise.
/*Inserts the value val into the tree as a new node.
Returns false if val already exists in the tree, and true otherwise.*/
bool BinarySearchTree::insert(DataType val) {
    Node* newNode = new BinarySearchTree::Node();
    root_ = getRootNode();

    if (root_ == NULL) {
        root_ = newNode;
        return true;
    }

    Node* curr = root_;
    while (curr) {
        if (val < curr->data) {
            if (!curr->left) {
                curr->left = newNode;
                return true;
            }
            curr = curr->left;
        } else if (data > curr->data) {
            if (!curr->right) {
                curr->right = newNode;
                return true;
            }
            curr = curr->right;
        } else {
            // Node with value already exists in the tree
            delete newNode;
            newNode = nullptr; 
            return false;
        }
    }
}


// Insert function definition.
BST* BST ::Insert(BST* root, int value){
    if (root == NULL) {
        return true;
    } else if (value < root->data) {
        return insertHelper(root->left, value);
    } else if (value > root->data) {
        return insertHelper(root->right, value);
    } else {
        return false; // Node with value already exists in the tree
    }
}


// Removes the node with the value val from the tree. Returns true if successful, and false otherwise.
/*Removes the node with the value `val` from the tree.
Returns true if successful, and false otherwise. 

Note: when the to-be-removed node has two child nodes, replace the value with the predecessor (rather than successor).
This implementation will be different from the demo code used in the lecture, which used the successor.*/
bool BinarySearchTree::remove(DataType val) {

# Deleting a node
def deleteNode(root, key):

    # Return if the tree is empty
    if root is None:
        return root

    # Find the node to be deleted
    if key < root.key:
        root.left = deleteNode(root.left, key)
    elif(key > root.key):
        root.right = deleteNode(root.right, key)
    else:
        # If the node is with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # If the node has two children,
        # place the inorder successor in position of the node to be deleted
        temp = minValueNode(root.right)

        root.key = temp.key

        # Delete the inorder successor
        root.right = deleteNode(root.right, temp.key)

    return root


    Node* findMinNode(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    Node* removeNode(Node* node, int data) {
        if (!node) {
            return node;
        }

        if (data < node->data) {
            node->left = removeNode(node->left, data);
        } else if (data > node->data) {
            node->right = removeNode(node->right, data);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* minNode = findMinNode(node->right);
                node->data = minNode->data;
                node->right = removeNode(node->right, minNode->data);
            }
        }

        return node;
    }



}

/*OPTIONAL. This function is not necessary for
1) about binary search tree, but it may help you when you implement AVL tree in
2) Given Node* n that is a pointer pointing to a node in the tree, this function calculates the balance value of Node* n and repeat this for all the ancestors of `Node* n`. 

Note that there are other methods to implement AVL tree properly without the eed to implement this function, so it is optional.*/
void updateNodeBalance(Node* n) {

}
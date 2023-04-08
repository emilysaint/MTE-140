#ifndef LAB3_AVL_TREE_H
#define LAB3_AVL_TREE_H

#include "binary-search-tree.h"

class AVLTree : public BinarySearchTree {
public:
    // Overriden insert and remove functions
    // Do not modify these definitions

    // The AVL tree should be kept balanced after calling just insert or remove.
    bool insert(DataType val);
    bool remove(DataType val);

    int Height(AVLTreeNode *T);

    // Default constructor to initialize the root.
    AVLTree();

    // Destructor of the class BinarySearchTree. It deallocates the memory
    // space allocated for the binary search tree.
    ~AVLTree();

    // Define additional functions and attributes below if you need
    
    struct Node {
        // Sets the left and right children to NULL, and initializes val.
        Node(DataType newval);

        DataType val;    // Value of the node.
        Node* left;      // Pointer to the left node.
        Node* right;     // Pointer to the right node.
    };

private:
    friend class BinarySearchTreeTest;
    friend class AVLTreeTest;

    // Pointer to the root node of the tree.
    Node* root_;
};

#endif  // LAB3_AVL_TREE_H
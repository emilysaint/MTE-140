#include "binary-search-tree.h"

#include <iostream>
#include <queue>

typedef BinarySearchTree::DataType DataType;
typedef BinarySearchTree::Node Node;

using namespace std;

BinarySearchTree::Node::Node(DataType new_val) : val(new_val)  {
    left  = nullptr;
    right = nullptr;
}


int BinarySearchTree::getNodeDepth(Node* n) const {

    if (n == nullptr)
        return -1;
    
    // Find the depth of the left and right subtree.
    int left_depth = 0, right_depth = 0;
    left_depth  = getNodeDepth(n->left)  + 1;
    right_depth = getNodeDepth(n->right) + 1;
    
    // If the depth of left is bigger, return it.
    if (left_depth > right_depth)
        return left_depth;
    
    //else, return the right.
    return right_depth;
}


BinarySearchTree::BinarySearchTree() {
    root_ = nullptr;
    size_ = 0;
}


BinarySearchTree::~BinarySearchTree() {
    
    // Keep track of the next nodes to delete.
    std::queue<Node*> q;

    // If the root exists... seed the process.
    if (root_ != nullptr)
        q.push(root_);

    // While there are still nodes to be deleted...
    while (!q.empty()) {

        // Get the node and remove it from the jobs
        Node* cur = q.front();
        q.pop();

        // Check the left and right children,
        // if they exist, add them to the jobs.
        if (cur->left != nullptr)
            q.push(cur->left);
        if (cur->right != nullptr)
            q.push(cur->right);

        // Now it's safe to delete the current node.
        delete cur;
    }
}


unsigned int BinarySearchTree::size() const {
    return size_;
}


DataType BinarySearchTree::max() const {

    // Go all the way right, until the next right
    // node doesn't exist (is nullptr).
    Node* cur = root_;
    while (cur->right != nullptr)
        cur = cur->right;

    // The node we end up at, is the node with the max value.
    return cur->val;
}


DataType BinarySearchTree::min() const {

    // Go all the way left, until the next left
    // node doesn't exist (is nullptr).
    Node* cur = root_;
    while (cur->left != nullptr)
        cur = cur->left;

    // The node we end up at, is the node with the min value. 
    return cur->val;
}


unsigned int BinarySearchTree::depth() const {
    // Seed the getNodeDepth function, by
    // getting the depth of the root node.
    return getNodeDepth(root_);
}


void BinarySearchTree::print() const {

    // Keep track of the nodes, to print in a 
    // breadth first (level order) traversal.
    std::queue<Node*> q;

    // Seed the jobs with the root.
    if (root_ != nullptr)
        q.push(root_);
    
    // Walk through the tree, adding nodes to the 
    // queue level-by-level.
    std::cout << "(";
    while (!q.empty()) {

        // Get the current node from the queue, and remove it.
        Node* cur = q.front();
        q.pop();

        // Print out the nodes value.
        std::cout << cur->val << " ";

        // Check to see if the current node has left or right children,
        // if they exist, add them to the queue.
        if (cur->left != nullptr)
            q.push(cur->left);
        if (cur->right != nullptr)
            q.push(cur->right);
    }
    std::cout << ")" << std::endl;
}


bool BinarySearchTree::exists(DataType val) const {

    // Run a binary-search on the tree, starting at the root.
    Node* cur = root_;

    // Loop until cur is the nullptr.
    while (cur != nullptr) {

        if (cur->val == val) {

            // Return true when the value is found
            return true;

        } else if (val < cur->val) {

            // Go left, if the value we're looking for 
            // is less than the current value.
            cur = cur->left;

        } else {

            // Go right otherwise.
            cur = cur->right;
        }
    }

    // If we've hit the nullptr somewhere,
    // then the value is not found in the tree.
    return false;
}


Node* BinarySearchTree::getRootNode() {
    return root_;
}


Node** BinarySearchTree::getRootNodeAddress() {
    return &root_;
}


bool BinarySearchTree::insert(DataType val) {

    // If the root node is the nullptr, then the tree is empty.
    if (root_ == nullptr) {
        root_ = new Node(val);
        size_++;
        return true;
    } 
    
    Node* parent;
    Node* cur = root_;
    while (cur != nullptr) {

        if (val == cur->val) {

            // Don't allow duplicate entires in the tree.
            return false;

        } else if (val < cur->val) {

            // If the value to insert is less than the current value, 
            // then it belongs in the current nodes left subtree.
            parent = cur;
            cur = cur->left;

        } else {

            // Else, the value to insert is more than the current value,
            // meaning it belongs in the current nodes right subtree.
            parent = cur;
            cur = cur->right;
        }
    }

    // Once current is the nullptr, we can insert the new node in the
    // position of the left/right child of the parent (previous node).
    Node* new_node = new Node(val);
    if (val < parent->val) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    // Increase the size and return successful.
    size_++;
    return true;
}


Node* findPredecessor(Node* ptr) {
    // Return a pointer to this nodes right-most-child.
    while (ptr->right != nullptr)
        ptr = ptr->right;
    return ptr;
}


bool BinarySearchTree::remove(DataType val) {

    // Check to make sure the root node exists, if not, remove is impossible.
    if (root_ == nullptr)
        return false;

    // Set up search for the node to remove.
    Node* cur = root_;
    Node* parent = root_;
    bool found = false;
    bool is_left_child = false;

    // Loop until we've hit the nullptr, 
    // or the value to remove has been found.
    while (cur != nullptr) {

        if (cur->val == val) {

            found = true;
            break;

        } else if (val < cur->val) {

            parent = cur;
            cur = cur->left;
            is_left_child = true;

        } else {

            parent = cur;
            cur = cur->right;
            is_left_child = false;

        }
    }

    // If the value wasn't found, we can return unsuccessful here.
    if (!found) return false;

    // Case 1: Node to remove has left and right children.
    if (cur->left != nullptr && cur->right != nullptr) {

        // Get the lefts-most-right child.
        Node* predecessor = findPredecessor(cur->left);

        // Hold onto this value.
        int predecessor_value = predecessor->val;

        // Recursively remove the node that has this value. 
        remove(predecessor_value);

        // One removed, replace the current nodes value with this one.
        cur->val = predecessor_value;

        // Decrement and return successful.
        size_--;
        return true;
    }

    // Case 2: Node to remove only has right child (left is nullptr).
    if (cur->left != nullptr) {

        // Handle the root remove case.
        if (cur == root_) {
            root_ = cur->left;
        }

        // Repoint the parent node to currents left.
        if (is_left_child) {
            parent->left = cur->left;
        } else {
            parent->right = cur->left;
        }

        // Safe to remove current now. Decrement and return successful.
        delete cur;
        size_--;
        return true;
    }
    
    // Case 3: Node to remove only has left child (right is nullptr).
    if (cur->right != nullptr) {

        // Handle the root remove case.
        if (cur == root_) {
            root_ = cur->right;
        }

        // Repoint the parent node to currents right.
        if (is_left_child) {
            parent->left = cur->right;
        } else {
            parent->right = cur->right;
        }

        // Safe to remove current now. Decrement and return successful.
        delete cur;
        size_--;
        return true;
    }

    // Else, Case 4: Node to remove has no children (left and right are nullptr)/

    // Handle the root remove case.
    if (cur == root_) {
        delete root_;
        root_ = nullptr;
        size_--;
        return true;
    }

    // Repoint the parent node to a nullptr.
    if (is_left_child)
        parent->left = nullptr;
    else
        parent->right = nullptr;

    // Safe to remove current now. Decrement and return successful.
    delete cur;
    size_--;
    return true;
}

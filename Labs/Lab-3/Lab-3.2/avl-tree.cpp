#include "avl-tree.h";
#include <iostream>
using namespace std;
// #include "binary-search-tree.cpp";


AVLTree::Node::Node(DataType newval) {
    val = newval;        // Value of the node.
    left = nullptr;      // Pointer to the left node.
    right = nullptr;     // Pointer to the right node.
}

AVLTree::AVLTree() {
    root_ = nullptr; // ? Node* root_ = new Node;
}

void destructorMthd(AVLTree::Node* n) {
    if (n != nullptr) {
        destructorMthd(n->left);
        destructorMthd(n->right);
        delete n;
        n = nullptr;
    }
}

AVLTree::~AVLTree() {
    Node* curr = root_;
    destructorMthd(curr);
    root_ = nullptr;
}


/*
- You need to implement the new AVL versions of insert and remove operations that keep the tree balanced. 
- They have been heavily introduced in the lectures with pseudocode and codes for parts of them. 
- When defining the AVL version of them, you may want to call the Binary Search Tree version of insert and 
    remove inherited from your Binary Search Tree class, using BinarySearchTree::insert or BinarySearchTree::remove, 
    to insert or remove the node from the tree, respectively. 
- After that, you need to ensure that the tree is kept balanced by applying the appropriate AVL tree rotations.

- Do not modify the signatures of the insert and remove functions to ensure that the test cases pass. 
- The AVL tree should be kept balanced after calling just insert or remove, 
    so any re-balancing operations should happen within these functions rather than outside of them.
- You may create additional functions and/or attributes in the .h and .cpp files to help complete the tasks, if needed.

- You are encouraged to utilize the BinarySearchTree implementation from your lab3.1 submission, 
    however, we have made available solution for you to utilize. 
- It can be found on Learn under the Lab Solutions section.

Note: if you utilize our solution you will need to rename your BinarySearchTree implementation to 
    binary-search-tree-<WATIAM ID>.cpp and binary-search-tree-<WATIAM ID>.h, 
    and insert the files from the solution in your repository. 
*/
bool AVLTree::insert(DataType val) {
    Node* pt = root_;
    Node* N = new Node*(val); 
    AVL_Insert(pT, N);
}

//ptr to a ptr to hange root, nothing changes for N
bool AVL_Insert(AVLTree::Node **pT, AVLTree::Node *N){
    //Use the regular BST Insert operation, insert new Node N.

    bool result = BinarySearchTree::insert(pT, N);

    if(result == false) return false;

    //Find out if any of Ns ancestors is unbalanced. If not, job done and return.
    //If so, find out the pointer to the unbalanced ancestor that is closest to N.

    AVLTree *root_; //??
    root_ = *pT;

    //special case, if N is inserted at the root node, nothing unbalanced, just return.
    if(root->val == N->val) return true;

    AVLTree *temp; //??
    temp = root_;
    AVLTree *temp_parent;
    AVLTree *alpha = NULL;

    do{
        temp_parent = temp;
        // normal traversing
        // go to the right
        if(N->val > temp->val) temp = temp->rightChild;
        // go to the left =
        else if (N->val < temp->val) temp =  temp->leftChild;
        //now, check if temp_parent is unbalanced.
        int leftHeight = Height(temp_parent->leftChild);
        int rightHeight = Height(temp_parent->rightChild);
        if( abs(leftHeight - rightHeight) >= 2 ) alpha = temp_parent;

    } while ( temp->val != N->val  );

    if(!alpha) return true;

    //Then re-balance the AVL tree using one of the four rotations, depending on the cases.
    if ( N->val < alpha->val && N->val < alpha->leftChild->val  ) SingleRightRotation (pT, alpha);
    else if (N->val > alpha->val && N->val > alpha->rightChild->val ) SingleLeftRotation(pT, alpha);
    else if ( N->val < alpha->val && N->val > alpha->leftChild->val ) LeftRightRotation(pT, alpha);
    else if (N->val > alpha->val && N->val < alpha->rightChild->val ) RightLeftRotation(pT, alpha);

    return true;
}


/*
bool Insert(AVLTreeNode **pT, AVLTreeNode *N){
/////////////////////////////////
    AVLTreeNode *T;
    T = *pT;

    // recursive version
    if(*pT == NULL) { //when input *pT is NULL, this is the root = NULL case, nothing in the tree.
        *pT = N; //If T is NULL, insert the node as the root of T, then return true and terminate
        return true;
    }
    //Compare the desired val val KN with the val value of the current node KT
    if (N->val == T->val) {
        return false;  //If KN == KT, then return false and terminate
    }
    else if (N->val < T->val) {
        if(T->leftChild == NULL) {
            T->leftChild = N;
            return true;
        }
        else return Insert( &T->leftChild,  N ); //If KN < KT, then continue insertion in the left subtree of T
    }
    else {
        if( T->rightChild == NULL) {
            T->rightChild = N;
            return true;
        }
        else return Insert( &T->rightChild,  N ); 	//If KN > KT, then continue insertion in the right subtree of T
    }


    //may need to do size++ when this function is included in a class of BST

/////////////////////////////////
}
*/


// REMOVE FUNCTION
bool AVLTree::remove(DataType val) {
    Node* pt = root_;
    // Node* N = new Node*(val); 
    Delete(pT, val);
}


// REMOVE HELPER FUNCTION
bool removeHelper(AVLTree::Node **pT, int K){
    AVLTree *T;
    T = *pT;

    //Find D in T (similar to Search)
    AVLTree* curr = T;
    AVLTree* parent = NULL;
    bool isLeftChild = false;
    bool found = false;
    while (curr != NULL) {
        if (curr->val == K) {
            found = true;
            break;
        }
        else if (K < curr->val){
            parent = curr;
            curr = curr->left;
            isLeftChild = true;
        }
        else {
            parent = curr;
            curr = curr->right;
            isLeftChild = false;
        }
    }

    //If D cannot be found, return false
    if(found == false) return false;

    //If D is found, then do the following:
    //If D is a leaf node in T (no child), remove it, then return true and terminate
    if(curr->left == NULL && curr->right == NULL ){
        //a special case it that if current_node is the root node
        if(curr == T){
            delete *pT;
            *pT = NULL;
            return true;
        }

        //if it is not the root node.
        delete curr;
        if(isLeftChild) parent->left = NULL;
        else parent->right = NULL;
        return true;
    }

    //If D has only one child node, cut D from the tree, and link D's parent directly to D's only child.
    if(curr->left != NULL && curr->right == NULL){ // left child is not empty, right child is empty
        if(isLeftChild) parent->left = curr->left;
        else parent->right = curr->left;
        delete curr;
        return true;
    }
    else if (curr->left == NULL && curr->right != NULL) { // right child is not empty, left child is empty
        if(isLeftChild) parent->left = curr->right;
        else parent->right = curr->right;
        delete curr;
        return true;
    }


    //If D has two child nodes, swap the vals with the predecessor (or successor), delete the predecessor (or successor) respectively, and then return true and terminate
    if(curr->left != NULL && curr->right != NULL ){
        //Successor is the smallest val in the right subtree
        //find successor
        AVLTree *successor = curr->right;
        isLeftChild = false;  // at the first step, successor is the right child of its parent.

        AVLTree *successor_parent = curr;

        while(successor->left != NULL){
            successor_parent = successor;
            successor = successor->left;
            isLeftChild = true;
        }

        curr->val = successor->val;
        curr->val = successor->val;


        //here, in fact, should also check if successor is a leaf node or a branch node with only one child.
        // successor must have leftchild empty; because if it is not empty, should have used the leftchild as successor

        //if it is the leaf node
        if(successor->right == NULL ){
            if(isLeftChild)	successor_parent->left = NULL;
            else 			successor_parent->right = NULL;
        }
        else {  //if it is the branch node. its right child is not empty
            if(isLeftChild)	successor_parent->left = successor->right;
            else 			successor_parent->right = successor->right;

        }
        delete successor;
        return true;
    }
    //may need to do size-- when this function is included in a class
}

// SINGLE LEFT ROTATION FUNCTION
void SingleLeftRotation (AVLTree::Node **pT, AVLTree::Node *alpha){
    //Input is alpha
    //A is alpha's right
    AVLTree *A = alpha->right;

    //alphas right = A's left
    alpha->right = A->left;

    //A's left = alpha
    A->left = alpha;


    //If alpha was the root of the whole tree, make A to be the new root.
    if (*pT == alpha){
        *pT = A;
    }
    else {
        //Let alpha's parent take A as the new child.

        //find 	alphas parent
        AVLTree *temp = *pT;
        AVLTree **parentPointerToAlpha = NULL;
        do{
            if(alpha->val > temp->val){
                parentPointerToAlpha = &temp->right;
                temp = temp->right;
            }
            else if (alpha->val < temp->val){
                parentPointerToAlpha = &temp->left;
                temp = temp->left;
            }
        } while (temp->val != alpha->val);

        *parentPointerToAlpha = A;
    }
}

// SINGLE RIGHT ROTATION FUNCTION
void SingleRightRotation (AVLTree::Node **pT, AVLTree::Node *alpha){
    //Input is alpha
    //A is alpha's left
    AVLTree *A = alpha->left;

    //alphas left = A's right
    alpha->left = A->right;

    //A's right = alpha
    A->right = alpha;

    //If alpha was the root of the whole tree, make A to be the new root.
    if (*pT == alpha){
        *pT = A;
    }
    else {
        //Let alpha's parent take A as the new child.

        //find 	alphas parent
        AVLTree *temp = *pT;
        AVLTree **parentPointerToAlpha = NULL;
        do{
            if(alpha->val > temp->val){
                parentPointerToAlpha = &temp->right
                temp = temp->right;
            }
            else if (alpha->val < temp->val){
                parentPointerToAlpha = &temp->left;
                temp = temp->left;
            }
        } while (temp->val != alpha->val);
        *parentPointerToAlpha = A;
    }
}

// RIGHT LEFT ROTATION FUNCTION
void RightLeftRotation (AVLTree::Node **pT, AVLTree::Node *alpha){
    //Input is alpha

    //A is alpha's right
    AVLTree *A = alpha->right;

    //B is A's left

    //Call single right rotation with input (A)
    SingleRightRotation(pT, A);

    //Call single left rotation with input (alpha)
    SingleLeftRotation(pT, alpha);
}

// LEFT RIGHT ROTATION FUNCTION
void LeftRightRotation (AVLTree::Node **pT, AVLTree::Node *alpha){
    //Input is alpha

    //A is alpha's left
    AVLTree *A = alpha->left;

    //B is A's right

    //Call single left rotation with input (A)
    SingleLeftRotation(pT, A);

    //Call single right rotation with input (alpha)
    SingleRightRotation(pT, alpha);
}

// HEIGHT FUNCTION
int Height(AVLTree::Node *T){
    if(T == NULL){
        return -1;
    }
    else if (T->left== NULL && T->right == NULL){
        return 0;
    }
    else{
        return 1 + max(Height(T->left), Height(T->right));
    }
}

// SEARCH FUNCTION
// Itterative
string Search(AVLTree::Node* T, int K){
    AVLTree* curr = T;

    while (curr != NULL) {
        if (curr->val == K){
            return curr->val;
        }
        else if (K < curr->val){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return "Search failed. No such val.";
}

// OTHER FUNCTIONS
// void PreOrderPrint(AVLTreeNode* T){  // recursive version.
//     if (T == NULL) return;
//     cout<<(T->val)<< "(" <<(T->val)   <<"), "; // print root data or other processing
//     PreOrderPrint(T->leftChild);
//     PreOrderPrint(T->rightChild);
// }
// void InOrderPrint(AVLTreeNode* T){	// recursive version.
//     if (T == NULL) return;
//     InOrderPrint(T->leftChild);
//     cout<<(T->val)<< "(" <<(T->val)   <<"), "; // print root data or other processing
//     InOrderPrint(T->rightChild);
// }
// void PostOrderPrint(AVLTreeNode* T){	// recursive version.
//     if (T == NULL) return;
//     PostOrderPrint(T->leftChild);
//     PostOrderPrint(T->rightChild);
//     cout<<(T->val)<< "(" <<(T->val)   <<"), "; // print root data or other processing
// }
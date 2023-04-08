# Assignment #3, Part #2 of 2

<br>

- The header file `avl-tree.h`, which is explained below, provides the structure of the AVLTree class with declarations of member functions.
- Note that the AVLTree class is an extension through inheritance of your `BinarySearchTree` class. 
- If you are not familiar with the concept of inheritance, 
    - e.g., how to define and use inherited variables and functions, read a simple tutorial here: https://msdn.microsoft.com/en-us/library/84eaw35x.aspx.
- For this part of assignment, you need to modify avl-tree.cpp and maybe also avl-tree.h if necessary.

<br>

### Instruction
Sign in to GitLab and verify that you have a project set up for your Lab Assignment 3 (lab 3) at https://git.uwaterloo.ca/mte140-2301/a3/WATIAM_ID with the following files.

YOUR-WATIAM-ID
- `CMakeLists.txt`
- `README.md`
- `binary-search-tree.cpp`
- `binary-search-tree.h`
- `avl-tree.cpp`
- `avl-tree.h`
- `test.cpp`

<br>

### Description
You need to implement the new AVL versions of insert and remove operations that keep the tree balanced. 
Place your code into `avl-tree.cpp`. 
They have been heavily introduced in the lectures with pseudocode and codes for parts of them. 
When defining the AVL version of them, you may want to call the Binary Search Tree version of insert and remove inherited from your Binary Search Tree class, using `BinarySearchTree::insert` or `BinarySearchTree::remove`, to insert or remove the node from the tree, respectively. 
After that, you need to ensure that the tree is kept balanced by applying the appropriate AVL tree rotations.

Do not modify the signatures of the insert and remove functions to ensure that the test cases pass. 
The AVL tree should be kept balanced after calling just insert or remove, so any re-balancing operations should happen within these functions rather than outside of them.
You may create additional functions and/or attributes in the .h and .cpp files to help complete the tasks, if needed.

You are encouraged to utilize the BinarySearchTree implementation from your lab3.1 submission, however, we have made available solution for you to utilize. 
It can be found on Learn under the Lab Solutions section.

Note: if you utilize our solution you will need to rename your BinarySearchTree implementation to `binary-search-tree-<WATIAM ID>.cpp` and `binary-search-tree-<WATIAM ID>.h`, and insert the files from the solution in your repository. 
After copying the files, commit and push everything to GitLab, then check in the browser to ensure the files are uploaded.

<br>

### Marking
Part 2 counts 40% of Lab Assignment 3 i.e. 40 points in total. We will try different inputs and check your output. 
We will only test your program with syntactically and semantically correct inputs. 
Your program:
1) Runs and does not crash during the test: + 10 points.
2) Passes Test Cases: 30 points total (6 total test cases) i.e. + 5 points per each test case.
# Assignment #2.1 - Dynamic Stack Implementation
<br>

- In this lab, you will practice your knowledge about stack by implementing a data type called dynamic stack.
- You need to use dynamically **re-sizable array** to implement it.
- (Note that “dynamic” here means that the size of the array can change dynamically. 
- It is different from the meaning of “dynamic” in dynamic memory allocation.) 
- The header file dynamic-stack.h **(NO MODS)**, which is explained below, provides the structure of the DynamicStack class with declarations of member functions. 
- Do not modify the signatures of any of these functions. 
- You need to implement all of the public member functions listed in dynamic-stack.cpp.

<br>

## Instruction
Sign in to GitLab and verify that you have a project set up for your Lab Assignment 2 (lab 2)
at https://git.uwaterloo.ca/mte140-2301/a2/WATIAM_ID with the following files.
YOUR-WATIAM-ID
- CMakeLists.txt
- README.md
- dynamic-stack.cpp
- dynamic-stack.h
- circular-queue.cpp
- circular-queue.h
- test.cpp

For this part of the lab, you only need to modify `dynamic-stack.cpp` **(MODIFY ONLY)**. 

Do not change any part of the header file (dynamic-stack.h).

**You will want to design your own test case and code in test.cpp. It is optional and we will not grade this file.**

- We are selectively releasing 4 out of the 10 test cases that will be used to grade you. 
- The selective tests are meant to help you design the remaining cases in a similar way.
- We also provide a description for all 10 test cases within the test.cpp file to guide your design in the remaining cases.
- You can use the same procedures in the Optional Lab Assignment 0 to pull, edit, build, commit, and push your repo.

<br>
<hr>
<br>

## Description
The details of the header file dynamic-stack.h are as follows:
- Defined using `typedef`, StackItem is the kind of data that the stack will contain. 
- Being public, it can be accessed directly as `DynamicStack::StackItem`.
- StackItem EMPTY STACK is a static constant data member that will be used to indicate an empty stack. 
- (Note that any actual data value stored in the stack should not be the same as this value.) 
- Being public, it can be accessed directly as `DynamicStack::EMPTY STACK`.

<br>

#### Member variables:

1) `items` : An array of stack items. (Note that in C++, an array name is a pointer to the first element of the array.)
2) capacity : Maximum number of elements allowed in the current stack.
3) `size` : Current number of elements in the stack.
4) `init capacity` : Initial capacity of the array (i.e., the capacity used in the construc-
tor). This is used by pop() to determine if we should decrease the capacity.
Constructors and Destructor:
1) `DynamicStack()`: Default constructor of the class DynamicStack. It uses 16 as the initial capacity of the array and allocates the required memory space for the stack.
The function appropriately initializes the fields of the created empty stack.
2) `DynamicStack(unsigned int capacity)`: Parametric constructor of the class DynamicStack. It allocates the required memory space for the stack of the given capacity.
The function appropriately initializes the fields of the created empty stack.
3) `~DynamicStack()`: Destructor of the class DynamicStack. It deallocates the memory space allocated for the stack.

<br>

#### Constant member functions:
1) `int size() const`: Returns the number of items in the stack.
2) `bool empty() const`: Returns true if the stack is empty and false otherwise.
3) `void print() const`: Prints the stack items sequentially and in order, from the top to the bottom of the stack. 
(Note: it is mainly used to help you visualize the data. It will not be used in any test cases for grading.)
4) `StackItem peek() const`: Returns the value at the top of the stack without removing
it. If the stack is empty, it returns the EMPTY STACK constant instead.

<br>

#### Non-constant member functions:
1) `void push(StackItem value)`: Takes as an argument a StackItem value. If the stack
is not full, the value is pushed onto the stack. Otherwise, the capacity of the stack is
doubled, and the item is then pushed onto the resized stack.
2) `StackItem pop()`: Removes and returns the top item from the stack as long as the
stack is not empty. If the number of items remaining in the stack after popping is less
than or equal to one quarter of the capacity of the array, then the array is halved.
However, if the new halved capacity is less than the initial capacity, then no resizing takes place. Finally, If the stack is empty before the pop, the EMPTY STACK constant is returned.

<br>
<hr>
<br>

### Note
All indexes must start with 0.
Do not include <bits/stdc++.h>; instead, use individual standard headers such as <string>, <iostream> when needed.

<br>

### Marking
Part 1 counts 50% of Lab Assignment 2 i.e. 50 points in total. 
We will try different inputs and check your output. 
We will only test your program with syntactically and semantically correct inputs. Your program:
1) Runs and does not crash during the test: + 10 points.
2) Passes Test Cases: 40 points total + 4 points per each test case.
# Assignment #2.2 - Circular Queue Implementation
<br>

In this lab assignment, you will practice your knowledge about queue by implementing a data structure called Circular Queue. 

You need to use *circular array* to implement it.
The header file `circular-queue.h`, which is explained below, *provides the structure* of the `CircularQueue` class with declarations of member functions. 
Do not modify the signatures of any of these functions. Y
ou need to implement all of the public member functions listed in `circular-queue.cpp`.

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

For this part of assignment, 
- you only need to modify `circular-queue.cpp`. 
    - **Do not change any part of the header file (`circular-queue.h`)**.
- You will want to *design your own test case* and code in `test.cpp`. 
    - It is optional and we will not grade this file. 
    - We are selectively releasing 4 out of the 10 test cases that will be used to grade you. 
    - The selective tests are meant to help you design the remaining cases in a similar way. 
    - We also provide a description for all 8 test cases within the test.cpp file to guide your design in the remaining cases. 
- You can use the same procedures in the Optional Lab Assignment 0 to pull, edit, build, commit, and push your repo. 

<br>
<hr>
<br>

## Description
- The details of the header file circular-queue.h are as follows:
- QueueItem defines the kind of data that the queue will contain. Being public, it can be
- accessed directly as CircularQueue::QueueItem.
- QueueItem EMPTY QUEUE defines a constant that will be used to indicate an empty queue.
- (Note that any actual data value stored in the queue should not be the same as this value.)
- Being public, it can be accessed directly as CircularQueue::EMPTY QUEUE.

<br>

#### Member variables:

1) `items` : An array of queue items.
2) `head` : Index of the first element in the circular queue.
3) `tail` : Index of the element after the last item in the circular queue.
4) `capacity` : Maximum number of items in the queue.
5) `size` : Current number of items in the queue.

<br>

#### Constructors and Destructors:
1) `CircularQueue()`: Default constructor of the class CircularQueue. 
    It uses 16 as the capacity of the array and allocates the required memory space for the queue.
    The function appropriately initializes the fields of the created empty queue.
2) `CircularQueue(unsigned int capacity)`: Parametric constructor of the class CircularQueue.
    It allocates the required memory space for the queue of the given capacity. 
    The function appropriately initializes the fields of the created empty queue.
3) `~CircularQueue()`: Destructor of the class CircularQueue. 
    It deallocates the memory space allocated for the queue’s items. 

<br>

#### Constant member functions:
1) `int size() const`: Returns the number of items in the queue.
2) `bool empty() const`: Returns true if the queue is empty, and false otherwise.
3) `bool full() const`: Returns true if the queue is full, and false otherwise.
4) `void print() const`: Prints the queue items sequentially and in order, from the front to the rear Of the queue. 
    (Note: it is mainly used to help you visualize the data. 
    It will not be used in any test cases for grading.)
5) `QueueItem peek() const`: Returns the value at the front of the queue without removing it from the queue. 
    If the queue is empty, it returns the EMPTY QUEUE constant
instead

<br>

#### Non-constant member functions:
1) `bool enqueue(QueueItem value)`: Takes as an argument a QueueItem value. 
    If the queue is not at capacity, it inserts the value at the rear of the queue after the last item, and returns true. 
    If the insertion fails due to lack of space, it returns false.
2) `QueueItem dequeue()`: Removes the item from the front of the queue and returns it.
    If the queue is empty, it returns the EMPTY QUEUE constant instead. 

<br>
<hr>
<br>

### Note
All indexes must start with 0.
Do not include <bits/stdc++.h>; instead, use individual standard headers such as <string>, <iostream> when needed.

<br>

### Marking
Part 2 counts 50% of Lab Assignment 2 i.e. 50 points in total. 
We will try different inputs and check your output. 
We will only test your program with syntactically and semantically correct inputs. Your program:
1) Runs and does not crash during the test: + 10 points.
2) Passes Test Cases: 40 points total + 4 points per each test case.
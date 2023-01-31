# MTE-140 Lab Assignment 1

Instructions for this lab can be found as a PDF on Learn
Follow the instruction to finish and submit your assignment
Commit your changes and push them to GitLab
Ensure your changes are visible on GitLab prior to the due date

<br>

## Lab 1 Part 1
- released on Friday January 27 at 10:00AM 
- due on Friday February 10 at 11:59PM EST
*Lab 1 consists of 2 parts divided on 3 week/labs. In the first part you will need to implement a sequential list. Follow the instruction file.

Exceptionally for this part only, I will release test cases we use for autograding to help you understand how we do it and build your own. In future labs, these will not be provided and you will be encouraged to design your own tests.

Additionally for this part, I will release some tips to help you get used to the fundamentals used in the labs.

Tutorial will cover sequential list. 

<br>

***

## INSTRUCTIONS - Sequential List Implementation
<br>

## Purpose of this assignment
In this lab, you will practice your knowledge about arrays by implementing a data type called sequential list. 

The header file sequential-list.h, which is explained below, provides the structure of the `SequentialList` class with declarations of member functions.

**Do not modify the signatures of any of these functions.** 

<mark style="background-color:#7f9977;"> 
You need to implement all of the public member functions listed in sequential-list.cpp. Note that we set a maximum capacity for this list. </mark>

*That is, when the capacity is reached, the list cannot take any more items.
You cannot use any built-in C++ STL for arrays such as the <vector> library. Using them is an automatic zero grade

<br>

## Instruction
Sign in to GitLab and verify that you have a project set up for your Lab Assignment 1 (lab_1) at https://git.uwaterloo.ca/mte140-2301/a1/WATIAM_ID with the following files.

```
YOUR-WATIAM-ID
CMakeLists.txt
README.md
doubly-linked-list.cpp
doubly-linked-list.h
sequential-list.cpp
sequential-list.h
test.cpp
```

For this part of assignment:
- <mark style="background-color:#7f9977;"> you only need to modify sequential-list.cpp. </mark> 
- <mark style="background-color:#7f9977;"> You can design your own test case and code in test.cpp. </mark> 
    - <mark style="background-color:#7f9977;"> It is optional and we will not grade this file. </mark>  
    - <mark style="background-color:#7f9977;"> I have decided to release the test.cpp code we will use for this time only to help you design your own test cases based on it. </mark> 
    - <mark style="background-color:#7f9977;"> Later Lab parts will not have the test codes provided as you will have to build your own to make sure your code works </mark> 
    - <mark style="background-color:#7f9977;"> You can use the same procedures in the Optional Lab Assignment 0 to pull, edit, build, commit, and push your repo. </mark> 

<br>

### Description
The details of the header file sequential-list.h are as follows:
- **DataType** defines the kind of data that the list will contain. 
    - Being public, it can be accessed directly as `SequentialList::DataType`

#### Member variables:
1) `data` : Pointer to the memory of array allocated to store the list data.
2) `capacity` : Returns the maximum number of elements the list can hold.
3) `size` : Returns the number of elements in the list.

#### Constructor and Destructor:
1) `SequentialList(unsigned int cap)`: Creates a new SequentialList with the given number of elements.
2) `∼SequentialList()`: Destructor, which frees all dynamically allocated memory.
3) `SequentialList(const SequentialList& rhs)`: Copy constructor, which copies one list rhs to another list. For this assignment, you don’t have to implement it. Just leave it blank in private section.
4) `SequentialList& operator=(const SequentialList& rhs)`: Assignment operator for the operations of the form list1 = list2. For this assignment, you don’t have to
implement it. Just leave it blank in private section.

#### Constant member functions:
1) Constant member functions are those function which do not modify class member variables.
2) unsigned int `size() const`: Returns the number of elements in the list.
3) unsigned int `capacity() const`: Returns the maximum number of elements the list can hold.
4) bool `empty() const`: Returns true if the list is empty, false otherwise.
5) bool `full() const`: Returns true if the list is at capacity, false otherwise.
6) `DataType select(unsigned int index) const`: Returns the value at the given index in the list. If index is invalid, return the value of the last element.
7) `unsigned int search(DataType val) const`: Searches for the given value, following the order from head to tail of the list, and returns the index of this value if found (for the first time the value is found). Returns the size of the list if no such value can be found in the list.
8) `void print() const`: Prints all elements in the list to the standard output.

### Non-constant member functions:
1) These functions can potentially modify member variable of the class.
2) `bool insert(DataType val, unsigned int index)`: Inserts a value into the list at a given index. Returns true if successful and false otherwise.
3) `bool insert front(DataType val)`: Inserts a value at the beginning of the list. Returns true if successful and false otherwise.
4) `bool insert back(DataType val)`: Inserts a value at the end of the list. Returns true if successful and false otherwise.
5) `bool remove(unsigned int index)`: Deletes the value from the list at the given index.
6) `bool remove front()`: Deletes the value from the beginning of the list. Returns true if successful and false otherwise.
7) `bool remove back()`: Deletes the value at the end of the list. Returns true if successfuland false otherwise.
8) `bool replace(unsigned int index, DataType val)`: Replaces the value at the given index with the given value.

<br>

## Notes
All indexes must start with 0.
Do not include `<bits/stdc++.h>`; instead, use individual standard headers such as `<string>`, `<iostream>` when needed.

<br>

## Marking
Part 1 counts 50% of Lab Assignment 1 i.e. *50 points in total*. We will try different inputs and check your output. We will only test your program with syntactically and semantically correct inputs. 
Your program:
1. Runs and does not crash during the test: *+ 10 points*.
2. Passes Test Cases: 40 points total *+ 4 points per each test case*.

 
<br>

***

<br>
 
## 1.1 Tips
<br>

1. Software design and programming is a time consuming process. The best way to learn is by practicing, so please allow yourself enough time to do so. We recommend that you use the whole week provided to work on every part of the lab assignment.

2. Read the instruction carefully. Start with pulling the project from GitLab.

3. The assignment description (posted on Learn) and the .h file explained all the data members and method methods of the class that you need to implement (or not). If you find anything not clear, you should ask the instructor or TAs for clarification.

4.  In `sequential-list.h`, understand `typedef int DataType;` 
    - This is a convenient feature. We use this line of code to define `DataType` as another name for `int`. 
    - The data structure will store data in the type of `DataType`. Currently, this means `int`; using `DataType` rather than directly using int has the benefit that
    - In the future, if we want to change `int` to `double`
        - we can simply change this one line of code rather than replacing all the `int` to `double` in the code.
        - (however, in this assignment, we don’t need to do that.)

5. In the constructor, remember to `initialize` the values of **capacity and size**. 
    - When just created, the *data structure should have no data item stored in it*
    - The member variable size that refers to the current number of items, *should be 0 when initiated*.

6. From the description of the member variables, we can see that we need to store data in an array.
    - **This array will be dynamically allocated memory**. 
    - *`data` is the pointer pointing to this array*. 
    - (Refer to Lecture 7 and online module on “Pointers Additional Resources”)

7. This array should be **dynamically allocated memory in the constructor**.
    - When doing that, *capacity should be the maximum number of items allowed in the array* 
    - (that is the size of the array when allocating memory for it; 
    - *note that this is not size, the number of elements/items currently in the list).

8. Be careful about the destructor. 
    - Remember that you need to *deallocate memory for all the dynamically allocated variables* (data in this case).
    - (Refer to Lecture 7 and online module on “Pointers Additional Resources”)

9. In `print()`, you can choose the format of printing for your own testing. 
    - The autograding code will not depend on the format in this print function.

10. For the *non-constant member functions*, you may want to first check if the operation is valid, 
    - depending on the input and the current state of the data in the object

11. For insert, besides inserting the `new` value at the given index location, 
    - remember to *shift all following items in the array (if any) one step further to the end of the list*, 
    - so the order of data items in the list will be maintained after inserting. 
    - <mark style="background-color:#cc7e78;"> And update size. </mark>

12. For `remove`, 
    - remember to *shift all the following items in the array (if any) one step to the front of the list*, 
    - so the order of data items in the list will be maintained. 
    - And update size.

13. For `replace`, 
    - it is considered as an *invalid input when no existing data has been stored at the input index*, 
    - and in this case, it should `return false and do nothing`.

14. For all functions that require a *return value*,
    - make sure all the *conditions in the function have their return statement with the proper value* 
    - (an if statement within the function for example).

15. Here are some descriptions of the test cases that we may use in autograding. 
    - Once you have coded the class, <mark style="background-color:#7f9977;"> you should create objects from your class and test them in your main function </mark> to see if it runs as expected.
    - Possible text cases
        ```ruby
        ”Test1: New empty list is valid”,
        ”Test2: insert front() and insert back() on zero-element list”,
        ”Test3: select() and search() work properly”,
        ”Test4: remove front() and remove back() on one-element list”,
        ”Test5: Inserting too many elements should fail”,
        ”Test6: insert front() keeps moving elements forward”,
        ”Test7: inserting at different positions in the list”,
        ”Test8: try to remove too many elements, then add a few elements”,
        ”Test9: lots of inserts and deletes, all of them valid”,
        ”Test10: lots of inserts and deletes, some of them invalid”
        ````
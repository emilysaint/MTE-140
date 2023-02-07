# Lecture 8 - Lab Test Cases Design
February 7, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Lab 1 <br> - LRN <br> - Exercise to try "*Week3_DoublyLinkedList_Insert_Remove_Print_template*"  |- Lab 1 Friday|

### General notes
- Coding is a means to end
- Exam is more comprehesion
- What are his exams like
- Suggested problems, sample exams, useful materials

### Recap
- 2 main types of List ADT: Sequential and linked lists
    - basic operations: delete, insert, select, replace, size
- Sequential linked lists (Arrays)
    - basic vs dynamic arrays
    - basic implantation
- Linked lists
    - Singly list full implementation
    - doubly linked list implementation
    - comparison with singly linked list


<br>
<hr>
<br>

## How to design test cases?
- General ideas
- Write code to test the algorithm with some input values.
- Output the results and see if they make sense.
- Also output the procedures and visualize them if it is helpful.
- How to select the values of input parameters for testing?
- If there are a finite number of input cases that can be tested in affordable time, test them all.
- Otherwise, select representative cases.
<br>

## How to select representative cases?
- Method 1. By analyzing the characteristics of the input values
- Analyze the range of input values
- Group them
- Pick some values that represent each group (Equivalence Partitioning)
<br>

## How to select representative cases?
- Method 1. By analyzing the characteristics of the input values
    - Analyze the range of input values
    - Group them
    - Pick some values that represent each group (Equivalence Partitioning)
    - Pick some values that represent the boundaries between groups (Boundary- Value Analysis)
<br>

## How to select representative cases?
- Method 2. By predicting in which cases the program may fail
- Test with invalid or unexpected inputs (Destructive Testing)
- E.g., invalid year int values, divided by zero, square root of negative
<br>

## How to select representative cases?
- Method 2. By predicting in which cases the program may fail
    - Test with invalid or unexpected inputs (Destructive Testing)
    - E.g., invalid year int values, divided by zero, square root of negative
- The above Methods 1 and 2 can be called black-box approach
    - or closed-box testing
    - They can be done without knowing/seeing the implementation of the
    code/function

- they should have boundaries
<br>

## How to select representative cases?
- White-box approach (open-box testing)
- Method 3. By understanding the code coverage
    - Select a variety of input cases to cover all different paths, conditions, branches, and statements in the code

```cpp
int foo(int n, int m) {
    int k = 0;
    if (n < 2) {
        if (m > 3){
            k = 5
        }
        else {
            k = 7;
        }
    } 
    else {
        k = 10;
    }

    return k;
}
```
- defining err codes

<br>
<hr>
<br>

## Summary

<br>

## Questions
- black/white (inside) box testing
- look at example code
- assert_func for checking values
- inserting breakpoins 


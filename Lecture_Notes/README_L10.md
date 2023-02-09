# Lecture 9 - More Recursion
February 7, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Lab 1 <br> - LRN <br> - Exercise to try |- Lab 1 Friday|

### Recap
- How to design recursive algorithms?
    - smaller versions of itself: recursive case
    - ending point(s): base case(s)
- Stack frame is created every time a function is called and it estores all variables in a frame on the stack memory
- Call tree and traces

<br>
<hr>
<br>

## Designing The Fibonacci Algorithm

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
𝐹0 𝐹1 𝐹2 𝐹3 𝐹4 𝐹5 𝐹6 𝐹7 𝐹8 𝐹9 𝐹10

- The Fibonacci Sequence starts with 0 and 1, and you keep on adding the sum of the two previous numbers
- Designing the Fibonacci algorithm recursively:
Designing The Fibonacci Algorithm
- To answer Q1, define a recursive case? 𝐹𝑛= 𝐹𝑛−1 + 𝐹𝑛−2 n⩾1
- To answer Q2, define an ending point i.e. a base case? 𝐹0 = 0, 𝐹1 = 1

<br>

## Fibonacci
Fibonacci algorith
```cpp
Algorithm: fibonacciRecursive
    Input: an integer n (e.g. 3)
    Output: the nth Fibonacci solution
        Step1 (base case): If n is 0, return the Fibonacci as 0
        Step2 (base case): If n is 1, return the Fibonacci as 1
        Step3 (recursive case): If n is greater than 1
    Calculate Fibonacci of n-1 recursively
    Calculate Fibonacci of n-2 recursively
    Return the Fibonacci of the nth number as the sum of the previous two results
```
Main code
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout << "Warning!input < 0." << endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    // fibonacciRecursive(n-1) is base case
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3);
stack frame for n = 3
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    // fibonacciRecursive(n-1) is base case
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3)
stack frame for n = 2
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3)
stack frame for n = 1
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1; // base case
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3)
stack frame for n = 2
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    // fibonacciRecursive(n-2) is base case
    // The function is called so a new stack frame for n - 2 = 0 is created now
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3)
stack frame for n = 0
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0; // base case
    else if (n == 1) return 1; 
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3)
stack frame for n = 2
This frame is now
solved and F2 returns 1
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1; 
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3);
stack frame for n = 3
The RHS is now called – creating a new frame for n-2 = 1
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    // fibonacciRecursive(n-2) is base case
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3);
stack frame for n = 1
This frame is now solved and F1 returns 
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1; // base case
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```
Lets see how it works for: int fibonacci = fibonacciRecursive(3);
stack frame for n = 3
F3 returns 2
```cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1; 
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```
NOTE: PICS ARE NOT INCLUDED

<br>

## Fibonacci Recursive vs Iterative
*Check the demo code: Week5_fibonacci*

Recursive
``` cpp
int fibonacciRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
```

Itterative
```cpp
int fibonacciNonRecursive (int n){
    if (n < 0) {
        cout<< "Warning!input < 0." <<endl;
        return 0;
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else {
        int result;
        int num1 = 0;
        int num2 = 1;
        for (int i = 2; i <= n; i++){
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        return result;
    }
}
```
*Non-recursive (iterative) version is more difficult to write! It is faster than the recursive version

<br>

## Fibonacci: Call Tree to find nth number
![L10_fib_tree1.jpg](Screenshots\L10_fib_tree1.jpg)

## Example: Call tree to find Fibonacci
![L10_fib_tree2.jpg](Screenshots\L10_fib_tree2.jpg)

*Factorial and Fibonacci are algorithms based on an approach called Divide and Conqueror
<br>

## Divide and Conquer Approach
1. Divide
    - Break problem into smaller subproblems
2. Conquer
    - Call recursively until subproblems are solved
3. Combine
    - Combine solutions of subproblems into solution for the original problem

<br>

## Divide and Conquer Approach
- In this approach, the problem is broken down to at least two subproblems;
therefore, multiple recursive calls need to be made.
- The Factorial and Fibonacci algorithms are based on this principle
- Many efficient algorithms are based on this approach, such as:
    - Quick sort and merge sort algorithms
    - Towers of Hanoi
    - Algorithm for finding the closest pair of points

<br>

## Towers of Hanoi
Towers of Hanoi algorithm
```cpp
Algorithm: HanoiTowers
    Input: number of pegs n, starting, destination and spare pegs
    Output: void
        Step0(base case): if n = 1 just move the disk from starting peg to destination peg
        Step1(recursive case): Move all n-1 disks (count from the top), from starting peg, to spare peg, with the help from destination peg
        Step2(recursive case): Move the nth disk (now nothing above it), from starting peg, to destination peg
    Step3(recursive case): Move all n-1 disks, from spare peg, to destination peg, with the help from the previous “starting” peg
```
Main code
```cpp
void moveRecursive(int n, Peg *startPeg, Peg *destinationPeg, Peg *sparePeg){
    if(n <= 0) return; // invalid case
    if (n == 1){//step 0
        destinationPeg->addTopDisk(startPeg->popTopDisk());
        //need to implement those functions
    }
    else{
        //step 1
        moveRecursive(n-1, startPeg, sparePeg, destinationPeg);
        //step 2
        moveRecursive(1, startPeg, destinationPeg, sparePeg);
        //step 3
        moveRecursive(n-1, sparePeg, destinationPeg, startPeg);
    }
}
```
<br>

## End of Recursion
- How to design recursive algorithms?
    - smaller versions of itself: recursive case
    - ending point(s): base case(s)
- Call tree
    - Stack frame is created every time a function is called and it stores all variables in a frame on the stack memory
    - Visualize the process as a tree and trace it
- Divide and Conqueror algorithms: Fibonacci, Factorial, Towers of Hanoi, etc

<br>
<hr>
<br>

## Summary

<br>

## Questions
- reccursion going back up?
- moving curent through list by looking withoutt doing
    `head->next->next-> ...`
# Lecture 9 - Introduction to Recursion
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
- Sequential linked lists (Arrays) → lab 1.1 due Feb 10
    - basic vs dynamic arrays
    - basic implementation
- Linked lists
    - singly: vanilla linked lists – one pointer to travel in one direction
    - doubly: two pointers to travel forward and backward → lab 1.2 due Feb 17
    - circularly: singly except that the tail pointer point to the head pointer

<br>
<hr>
<br>

## <mark style="background-color:#cc7e78;">  Introduction </mark>
Linked list: recursive call and basic operations were implemented using
iteration (loops)
```cpp
struct Node {
    DataType data;
    Node *next;
};
```
<br>

## Recursion
- Recursion as a problem solving strategy:
    - This approach of representing and solving a computing problem using smaller, recurrent versions of itself is referred to as recursion
- Recursion in coding:
    - a function in your code call itself as part of its own execution
<br>

## Recursion vs Iteration
- Theoretically, any recursive algorithm can be represented non-recursively  (iterative)
- Recursion is a powerful alternative for iteration (loops):
    - Neat and more elegant
    - Reduces the problem complexity
    - <mark> Requires skill and intuition </mark> – more challenging than iteration
- When to use recursion:
    - In problems where a recursive solution may be shorter and simpler to write/code than the corresponding iterative solution
*Recursion is not more efficient than itteration
<br>

## Designing Recursive Algorithms
- When designing recursive algorithms, answer the following two questions:
    - Q1: How to represent the given problem using smaller versions of itself? (i.e., how to design recursive case(s))
    - Q2: When does the problem reach its ending point? (i.e., how to design base
 case(s))
- To answer Q1, define what “smaller” means
    - Smaller could mean smaller input, but more precisely, smaller means closer to the ending point of the problem -> referred to as general (recursive) case
- To answer Q2, define what is the ending point
    - A problem reaches its ending point when there is a trivial answer to the problem -> referred to as base case
<br>

> 𝑎<sub>1</sub> = 1 <br>
𝑎<sub>𝑛+1</sub> = 1 + 𝑎<sub>𝑛</sub> (𝒏 ≥ 𝟏) <br>

> 𝑎<sub>1</sub> = 1 <br>
𝑎<sub>2</sub> = $\sqrt{1 + 1}$ <br>
𝑎<sub>3</sub> = $\sqrt{1 + 1 + 1}$ <br>
𝑎<sub>4</sub> = $\sqrt{1 + 1 + 1 + 1}$ <br>
𝑎<sub>5</sub> = $\sqrt{1 + 1 + 1 + 1 + 1}$ <br>

<font color="#eba459"> To answer Q1, define a recursive case? </font>
> a<sub>n+1</sub> = $\sqrt{1+a_n}$

<font color="#eba459"> To answer Q2, define an ending point i.e. a base case? </font>
> a<sub>1</sub> = 1

## Designing Recursive Algorithms
- Recursive algorithm components:
    - Base case:
        - the simplest version of the problem (e.g. 𝑎1 = 1)
        - can be answered directly
- Recursive case:
    - the case for which the problem is broken down into smaller versions of itself
        > 𝑎<sub>𝑛+1</sub> = $\sqrt{1 + a_{𝑛}}$
    - cannot be answered directly
<br>

## Example 1: Factorial Function
Consider the Factorial function, n!
- To compute 4!, compute 4 × 3 × 2 × 1
- However, the same function can be viewed as 4 × 3!
- That is, we can represent the same problem using a smaller version of itself (3!), which is then combined (4×) to obtain a solution to the original problem (4!)

<mark style="background-color:#cc7e78;"> 
- Recursive case: `𝑛! = 𝑛 × (𝑛 − 1)`! <br>
- Base case: the value of `0! = 1` (by definition)
</mark>

Alorithim
```cpp
Algorithm: factorialRecursive
    Input: an integer n (e.g. 4)
    Output: the factorial solution (resulting factorial of n)
    Step1 (base case): If n is 0, return the factorial as 1
    Step2 (recursive case): If n is greater than 0
    Calculate (n-1)! (recursively)
    Return the factorial of n which is n times that result
```
Main 
```cpp
int factorialRecursive (int n){
    if(n < 0) {
        cout<< "non-negative input!" << endl;
        return 0;
    }
    else if (n == 0) return 1;
    else return (n * factorialRecursive (n-1));
    }
```
When a function is called:
1. the stack allocates memory to store the function’s variables
2. those variables are stored in frame → this is called a stack frame
<br>

<font color="#cc7e78">
Stacked frames
- after done solving things in backward manner

1. stack frame for n = 3
    - The function is called so a new stack frame for n - 1 = 2 is created now n = 3
2. stack frame for n = 2
    - Another stack frame for 1 is created
3. Stack frame for 0 
    - is freed from the stack once a value is return
    then all subsequent stack frames are resolved in the same way
    `else if (n == 0) return 1;`
4. stack frame for n = 1
5. stack frame for n = 2
6. tack frame for n = 3

</font>

<br>

## <font color="#92b1d4">  General Steps to Create Recurssive Functions
1. base case
    - "last case"
    - return last/end val wanted
2. recurssive case
    - logic of looping
    - returing funtion call back again
3. return final
<br>

Copy for understanding 
</font>

```cpp
int factorial(int 0){
    if (n <0){
        return 0; 
    }
    else if (n ==0){
        return 1;
    }
    else {  
        return (n* factorial(n-1)) // creating new memory on the side, creating new "objects" and after the chain(pyramid) it gets rid of the "memory (stacked frame). Creates new stacked frame every time"
    }
}
```


## Example 1: Factorial Recursive vs Iterative
Recursive
```cpp
int factorialRecursive (int n){
if(n < 0) {
cout<< "non-negative
input!" <<endl;
return 0;
}
else if (n == 0) return 1;
else return (n * factorialRecursive (n-1));
}
```

Itterative
```cpp
int factorialNonRecursive (int n){
if(n < 0) {
cout<< "non-negative
input!" <<endl
return 0;
}
if (n == 0) return 1;
int result = 1;
for(int i = 1; i <= n; i++){
result = result * i;
}
return result;
}
```
Check `Week5_factorial` demo code

<br>

## Call Tree and Call Traces
o Allow visualization of function calls and recursion, where each call spawns smaller
representations of itself
o This is represented as tree branches that are branching out from the tree root
o To trace the calls, we start off from the top of node (root) of call tree and go all the way
down to the bottom of tree, which signifies the end of recursive calls
o Values at base case are defined, which are used to find the value of upper level of tree.
Then the process goes upward

<br>

## The Factorial: Call Tree to find nth number

> 𝐹(0) = 1, 𝐹(𝑛) = 𝑛 × 𝑛 − 1 ! (n⩾1)

<br>

## End of Lecture
- How to design recursive algorithms?
    - smaller versions of itself: recursive case
    - ending point(s): base case(s)
- Stack frame is created every time a function is called and it stores all variables in a frame on the stack memory
- Call tree and traces

<br>
<hr>
<br>

## Summary

<br>

## Questions
- reccursion going back up?
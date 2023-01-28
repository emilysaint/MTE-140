# Lecture 3
# C++ Implementation of Pointers
Jan 24, 2023

## To Dos
- Make sure to understand pointers
- Lab

<br>

## Comp Memory
- Static: allocated by complier in advances
- Dynamic: controlled by the program execution

<br>

## Memory Allocation
- memory poll is large but not infinate
- at the end of the program meomory is reallocated and freeded up

<br>

## Memory Space
- hexadeci - binary
- 32 vs 64 bit adress space - differenece in num bit for memory allocation

<br>

## Going from Hex to bin
...NA...
Using ram corresponds to how much memory we can use?

Ox155FFFF is hex


<br>

## Architechture of memory
![L4_ach_of_mem.JPG](Screenshots\L4_ach_of_mem.JPG)

## Static and Dynamic Memory
...NA...

<br >

## Ex 1

```ruby
//return variable 'a' plus 1
int testFunc1 (int a){ 
    //here, memory is statically allocated to 'a'
    //'a' is a variable within the scope of testFunc1
    cout << endl << "Inside function, address of 'a': " << &a << endl;
    a++;
    return a;
}
//after the end of this scope, local variables are automatically removed.
//their memory space is automatically released back to the pool (free for other usage)

int main() { 
    //main function also has its scope
    int x = 1, y = 10; //here, memory is statically allocated to x and y.
    cout << "Before function call: Value of x: "<< x << ". Address of x: " << &x << endl;
    cout << "Before function call: Value of y: "<< y << ". Address of y: " << &y << endl;

    cout << endl;

    cout << "Function call with input (x): " << testFunc1(x) << endl;
    cout << "Function call with input (y): " << testFunc1(y) << endl;

    cout << endl;
}
```
Output
```ruby
>> Function call without input (x):
Inside function, address of 'a': 0x7ffee62bea1c
2
Function call with input (y):
Inside function, adress of 'a': 0x7ffee62bea1c
11
```

<br>

## The new operator
```ruby
int *p; w
p = new int(17); //init *p to 17
```

Allocate memory with the size of the data type
return a pinter of the data type
normally 8bytes

```ruby
int *p
p = new int[5]

//resquest  8bytes to show the size of the array
//+5size of p
//5x4 = 10bytes
```

```ruby
int a[3] = {10, 20, 30}; 
a[0] = 10; 
a = ?
cout << a;
```

Output
```ruby
'memory address of a'
adress of a[0] pointer
*a = a[0]

// only have stored address of element 1 with arrays
// you cannot get memory adress of next element
a[1] = 20 // so this doesnt work 

```
Static memory doesnt allow you to replace element, yu have to shift everything down and loop through everything. Dynmic memory allows you to add/inset. 

<br>

## Memory Leaks

the memory will not be automatically released/de-allocated until
only in heap it will happen 
not in stack

```
int *p;     // this is pointing to a memory loc
p = new int(17);//Initializes *p to 17
```

..NA..

<br>

## Delete operator
- dealocating dyn mem, which means furture new operators will be able to allocate the mem space

```
```

<br>

## Dangling pointers
- dangling pointers is a non-null pointer that points to unallocated memort
- defere
```
```

<br>

## Avoid dangling pointers
..NA.. what
soln:
avoid dangling pointers by immediatelye assign point to NULL after delete
```ruby
delete p; 
p = NULL; 

// 0, or nullptr (as c++11)
if ...NA...
```

<br>

## COnstructor and destructors
- new operator calls a const for new objects
- del op calls a destr to be de-allocated the object

<br>

## Constructors
- a kind of class member function
    - automatically called


## Questions
- how to count bits of x16, 1-9 then a-g
- whats the correlation between ram, hex, memory allocation, 32/64
- dyn mem can only be allocated by pointers
- dyn mem inc size of list 
- how to init new mem
- memory leaking 
- del op 
- constructor- why create default day==1 and :month(monthValue), int main monthValue why is it highlighted=


struct - public
class - private

 Questions
 passby ref
 fields                       
 this                           
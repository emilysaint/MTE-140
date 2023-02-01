# Lecture 4 - Memory Allocation
Jan 24, 2023

<br>

### To Review
- Memory Space - tom's notes
- Hex to bin - tom's notes

<br>

|To Do                      |Deliverables               |
|---------------------------|---------------------------|

## Going from Hex to bin
Using ram corresponds to how much memory we can use?

memory of comp = ram (used while running programs) + hard drive
cpu executes instructions
gpu executes diff instructs (graphics)

Ox155FFFF is hex

![L4_Tom_hex_bin.jpeg](Screenshots\L4_Tom_hex_bin.jpeg)

<br>

## Architechture of memory - NA
![L4_ach_of_mem.JPG](Screenshots\L4_ach_of_mem.JPG)

<br>

## Static and Dynamic Memory
- during a program's lifetime, there are two ways to allocate memory spcare to each variable used in the program
- Static
    - vars def without `new` operator
    - has a lifetime within scope (ie a function)
    - at end of scope, var is auto destroyed
    - memory is auto de-allocated for other things in the program to use
- Dynamic
    - var def using `new` operator
    - has a lifetime with entire progran or untill user `delete` to manually de-allocate the memory space

<br >

## Ex 1

```ruby
# return variable 'a' plus 1
int testFunc1 (int a){ 
    # here, memory is statically allocated to 'a'
    # 'a' is a variable within the scope of testFunc1
    cout << endl << "Inside function, address of 'a': " << &a << endl;
    a++;
    return a;
}
# after the end of this scope, local variables are automatically removed.
# their memory space is automatically released back to the pool (free for other usage)

int main() { 
    # main function also has its scope
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
int *p;
p = new int(17); # init *p to 17

int = *p1; 
p1 = new int; 
# without init
# not recommended
cout<<*p1;
# will get whatever was previously left there in the 4 bytes space. Some unknow number 
```

Allocate memory with the size of the data type
return a pinter of the data type
normally 8bytes

*Attention Memory Leak: the memory will not be automatically released/de-allocated, untill end of the program or user `delete`.

```ruby
int *p
p = new int[5]

# resquest  8bytes to show the size of the array
# +5size of p
# 5x4 = 10bytes
```

```ruby
int a[3] = {10, 20, 30}; 
a[0] = 10; 
a = ?
cout << a;
```

Output
```ruby
# memory address of a
adress of a[0] pointer
*a = a[0]

# only have stored address of element 1 with arrays
# you cannot get memory adress of next element
a[1] = 20 # so this doesnt work 

```
Static memory doesnt allow you to replace element, yu have to shift everything down and loop through everything. Dynmic memory allows you to add/inset. 


<br>

## Memory Leaks

Memory leak
- a piece of memory that was previously allocated by a programmer (using `new`) is not properly de-allocated (using `delete`)
- eventhough that memory is no longer in use by the program, it is still `reserved`
- without `delete`, no `new` operator can allocate the same address allocated by a previous `new`.
- If a program has a lot of memory that hasn't been de-allocated, it could slow down the preformance
- if there is no memory left in the program, it could cause the program to crash

the memory will not be automatically released/de-allocated until
only in heap it will happen 
not in stack

```ruby
int *p; # this is pointing to a memory loc
p = new int(17); # Initializes *p to 17
```

<br>

## Delete operator
- dealocating dyn mem, which means furture `new` operators will be able to allocate the mem space

```ruby
int *p;
p = new int (17);  # init *p to 17
delete p; # but p still points there and is called a "dangling pointer"
```

<br>

## Dangling pointers
- dangling pointers is a non-null pointer that points to unallocated memory
- deferencing a dangling pointer may cause the program to crash
- avoid dangling pointers by immidiatley assign point to NULL after delete
```ruby
int *p; 
p = new int(17);
delete p; # if p is the de-ref using (*p), this leads to unpredictable results
p = NULL; # 0 or null ptr. if someone tries tri check p validity later, if(p) = False
```

<br>

## Constructor and destructors
- new operator calls a const for new objects
- del op calls a destr to be de-allocated the object

Constructors:
- A special kind of class member function
    - automatically called when an object of the class is instantiated
    - must be **public**
    - if no constructor is defined by the user, the systeme will create a default constructor
- Difference from other regular member functions
    - they must have **the same name** as the class
    - they **cannot return a value; not even void**
- Advantages
    - inti some or all member variavles of an object, simply the procedure
    - add code to validate the entered init value
    - other actions, ie, print to systen when an object is instantiated

```cpp
class MonthAndDay { 
private:
    int month;
    int day;
    void checkDate(); # check if the date is valid.
public:
    // constructors all seperate to change, we need get/set
    MonthAndDay(); // overload constructor with no argument condition 
    # note: no return value not even void
    MonthAndDay(int month Value); // overload 1 int condition
    MonthAndDay(int month Value, int dayValue); // overload 2 
    int condition;
    void output(); // note: require return value such as void
    ~MonthAndDay(); // destructor
}
```

Destructors:
- Automatically called when an object of the class is **deallocated**
    - if the memory is *statically* allocated, destructor is called when the object's scope is closed/ended
    - if the memory is *dynamically* allocated, destructor is called when explicitly `deleted`
- Destructor must be named the same as the class
    - with a **"~" (tiled)** sign preceding its name
    - each class has only one destructor
    ```cpp
    MonthAndDay(); // constructor
    ~MonthAndDay(); // destructor
    ```
```ruby
#include <iostream> 
using namespace std;
int* testFunc3 (int a){
# return a pointer
int *p1;
# p1 is a local variable
p1 = new int(a); # the address returned by new will not be automatically collected after the end of this function scope
# here, new operator allocates the memory dynamically/manually
cout << "Inside testFunc3, int value: "<< *p1 << " is allocated memory at address: " << p1 << endl;
return p1; # here return the pointer, i.e., return the memory address value
}
```

<br>
<hr>
<br>

## Summary
<br>

### Memory Allocation
- at the star of a program the operating system assigns the progra a memory pool (free space to use)
- memory pool is large but not infinate
- at the end of the program meomory is reallocated/de-allocated and freeded up

<br>

### Going from Hex to bin
![L4_Tom_hex_bin.jpeg](Screenshots\L4_Tom_hex_bin.jpeg)

<br>

### Architechture of memory - NA
![L4_ach_of_mem.JPG](Screenshots\L4_ach_of_mem.JPG)

<br>

### Static and Dynamic Memory
- during a program's lifetime, there are two ways to allocate memory spcare to each variable used in the program
- Static
    - has a lifetime within scope (ie a function)
    - at end of scope, var is auto destroyed
    - memory is auto de-allocated for other things in the program to use
- Dynamic
    - var def using `new` operator
    - has a lifetime with entire progran or untill user `delete` to manually de-allocate the memory space
    - controlled by the program execution

<br>

### The new operator
- Allocate memory with the size of the data type
return a pinter of the data type
- *Attention Memory Leak: the memory will not be automatically released/de-allocated, untill end of the program or user `delete`.
- Static memory doesnt allow you to replace element, yu have to shift everything down and loop through everything. Dynmic memory allows you to add/inset. 

<br>

### Memory Leaks
- a piece of memory that was previously allocated by a programmer (using `new`) is not properly de-allocated (using `delete`)
- eventhough that memory is no longer in use by the program, it is still `reserved`
- without `delete`, no `new` operator can allocate the same address allocated by a previous `new`.
- only in heap it will happen 
- not in stack

<br>

### Delete operator
- dealocating dyn mem, which means furture `new` operators will be able to allocate the mem space

<br>

### Dangling pointers
- dangling pointers is a non-null pointer that points to unallocated memory
- avoid dangling pointers by immidiatley assign point to NULL after delete

<br>

### Constructor and destructors
- new operator calls a const for new objects
- del op calls a destr to be de-allocated the object

Constructors:
- A special kind of class member function
    - automatically called when an object of the class is instantiated
    - must be **public**
    - if no constructor is defined by the user, the systeme will create a default constructor
- Difference from other regular member functions
    - they must have **the same name** as the class
    - they **cannot return a value; not even void**

Destructors:
- Automatically called when an object of the class is **deallocated**
    - if the memory is *statically* allocated, destructor is called when the object's scope is closed/ended
    - if the memory is *dynamically* allocated, destructor is called when explicitly `deleted`
- Destructor must be named the same as the class
    - with a **"~" (tiled)** sign preceding its name
    - each class has only one destructor

<br>

## Questions
I understand:
- how to count bits of x16, 1-9 then a-g
- dyn mem can only be allocated by pointers
- dyn mem inc size of list 
- how to init new mem
- memory leaking 
- del op 
- struct - public
- class - private

I don't understand:
- whats the correlation between ram, hex, memory allocation, 32/64
- constructor- why create default day==1 and :month(monthValue), int main monthValue why is it highlighted=

<br>

## To Review
- passby ref
- fields                       
- this                           
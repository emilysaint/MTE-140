# Lecture 7 - Sequential and Linked Lists Implementation
Jan 31, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Make sure to understand pointers <br> - LRN  |- Lab <br> - start lab|

### General notes
- Coding is a means to end
- Exam is more comprehesion
- What are his exams like
- Suggested problems, sample exams, useful materials =

<br>
<hr>
<br>

## Recap
- Implementing Nodes and Linked list class
- Basic operations as C++ functions
    - better to use constructors and destructors
- Types of Linked Lists
    - singly: vanilla linked lists – one pointer to travel in one direction
    - doubly: two pointers to travel forward and backward
    - circularly: singly except that the tail pointer point to the head pointer
- Abstract data type 
    - collection of data items given a name, purposem and a set of funcs that op on data items
    - <mark> only necessary info is shown externally to user whule underlying detais are hidden 
    - ex, keyboard
    - <mark> usually implemented using class and constructors. A collection of vals is associated to private data members and a set of basic ops is associated to public member funcs

<br>

## List ADT Introduction
- list ADT is a container stucture for storing a connected sequence of data items
- basic ops
    - `insert` data into the list at a specific loc
    - `delete` removes data from the list at a given pos
    - `select` returns a val stored at an input position
    - `replace` replace a val at a given pos
    - `size` tracjs abnd returns the num of elems in list

<br>

## List ADT **Insert**
`void insert(DataType value, int position):`
1. check special cases: position zero, <mark> first , last
2. inserts val into the list at pos and incs size by 1
3. <mark> aft inserting val at pos, data is shifted towards the list end by one
4. if size reaches the max cap - the list may be inc to accommodate new elems

<br>

## List ADT: **Delete**
`void remove(int position)`
1. check special cases: position zero, first, last
2. removes data from the list at a given pos and decs size by 1
3. <mark> aft inserting the val, all of exisiting data aft postion is moved towards the list front by one
4. <mark> alternatively, use a ptr to a Node as input, Node should not previously belong to list

<br>

## List ADT: **Select**
`DataType select (int position);`
1. Check special cases: position zero, first, last
2. Returns the value stores at a given position

<br>

## List ADT: **Replace**
`void replace (int position, DataType value);`
1. Check special cases: position zero, first, last
- Replaces val stored at a given pos with *a different* value
- <mark> Alternatively, may use a pointer to a Node as input. The node should not previously belong to the list

<br>

## List ADT: **Size**
`int size ();`
1. Tracks and returns the number of elements in the list.
*Note: this is not the capacity of the list (i.e., max possible size).

<br>

## List ADT Introduction pt 2
there are two types 
- sequencial
- linked

<br>

## Squential List (Array) Implementation
- **Allocate** a <mark> contiguos <mark> block of memory to store the data, and an index is available to provide direct acess to rand data items
- keep in mind: STL a version of sequential list is provided as the <mark> < vector > library
- characterized as 4 main members
     - **index** an integer usually starting from 0
     - **data** stored as an array
     - **capacity** the max number of elements that can be stored
     - **size** the num of elems currently in the list. Any index pos exceeding the current size  does not store a valid data

<br>

## Sequencial List (Array) Implementation
- Can be implemented with
    - basic array with fixed capacity - has to be determined at the moment of designing the program, before it is run
    - dynamic array with a dynamic capacity - assign memory during runtime using any var capacity
- dynamic arrays
    - create using the new operator on the <mark> heap

```ruby 
int *array = new int[size]; #size can be changed during run time!
Delete [] array; # do not forget to free the space
```
<mark> *dangling pointer, set array to null ptr, maybe since *array is init. How array ptr

<br>

## Sequential List **Initalization**
![L7_seq_list_init.jpg](Screenshots\L7_seq_list_init.jpg)

<br>

## Sequential List **Insert**
![L7_seq_list_insert.jpg](Screenshots\L7_seq_list_insert.jpg)
- If the size reaches capacity, capacity may be inc to accommodate new elems (dyn arrays)
- In the < vector > library, the capacity is inc on `push_back()` if out of space
- I t is important to test the validity of insert position,
    - e.g., <mark> exceeding tail position

<br>

## Sequential List **Delete**
![L7_seq_list_del.jpg](Screenshot\L7_seq_list_del.jpg)
*items are shifted twrds the front of the list. No gap left btwn elems

- If the size is significantly smaller than capacity, the list capacity can
be decreased
- In the < vector > library:
    - `shrink_to_fit()` can be called to try and reduce the capacity to size
    - <mark> does it doe this automaticaly
- `delete_front()` is the same as `delete(0)`
- `delete_end()` is the same as `delete(size-1)`

<br>

## Sequential List **Replace, Select and Size**
Replace
![L7_seq_list_replace.jpg](Screenshots\L7_seq_list_replace.jpg)

- **Select** Implemented as array lookup; 
    - >data[2] returns m (List ADT **Select** notes above)
- **Size** Implemented by returning the size val
    - >size() return 4 (List ADT **Size** notes above)

<br>

## Linked List
- Linked list are made of: 
    - nodes which are data structures that contains:
        - data items
        - pointers to other nodes in the sequence

    ![L7_linked_list.jpg](Screenshots\L7_linked_list.jpg)

- singly linked list extends to implementing the doubly linked list

    ![L7_singly_linked_list.jpg](Screenshots\L7_singly_linked_list.jpg)

<br>

## Doubly Linked List
- In a doubly linked list, each node has **two pointers**
    - one pointing to the previous node
    - one pointing to the next node
- The two-way double links allow iteration to move both forwards and backwards

    ![L7_doubly_linked_list.jpg](Screenshots\L7_doubly_linked_list.jpg)

- A node example in a doubly linked list

    ![L7_doubly_linked_list_nodes.jpg](Screenshots\L7_doubly_linked_list_nodes.jpg) 

<br>

## Doubly Linked List

Its implementation should keep track of the following:
- **head (or first)** pointer to the head or start of the list; <mark> set to NULL at start
- **tail (or last)** pointer to the end of the list; set to NULL at start
- **size** the number of inserted elements in the list; <mark> set to 0 at start

    ![L7_doubly_linked_list_implementation.jpg](Screenshots\L7_doubly_linked_list_implementation.jpg)

<br>

## Doubly Linked List **Insert**

`void insert(DataType value, int position)`
- Implemented similarly to singly List
    - just need account for the previous address (pointer)
    - move in 2 ways using them

    ![L7_doubly_linked_list_insert.jpg](Screenshots\L7_doubly_linked_list_insert.jpg)
    
Example: <mark> Four insert operations are applied to an empty doubly linked list
```ruby
insert('c',0) =>
insert('b',0) =>
insert('a',0) =>
insert('k',1) 
```
*Φ’s represent *NULL* ptr address values

<br>

## Doubly Linked List **Delete**
`void delete(int position)`
- Implemented similarly to singly linked list
    - <mark> it iterates in 2 ways through the list until position and removing that node

    ![L7_doubly_linked_list_delete.jpg](Screenshots\L7_doubly_linked_list_delete.jpg)


Example: two remove operations on the previous example
```ruby
remove (2) =>
remove (0)
```

<br>

## Doubly Linked List **Replace, Select and Size**
`void replace(int position, DataType value)`
- Implemented similarly to singly linked
    - it iterates in 2 ways through the list until position and replacing its value
    - Example: replace(1, ‘t’)
- `DataType select(int position)` Implemented by iterating (in 2 ways instead) through the list until position
- `int size()` Implemented by simply returning the size val

    ![L7_doubly_linked_list_replace.jpg](Screenshots\L7_doubly_linked_list_replace.jpg)

<br>

## Singly vs Doubly Linked Lists Comparison

|Aspect |Singly-linked |Doubly-linked|
|--|--|---|
|Iterate |One way |Two ways|
|Memory overhead |Less (one pointer per node)| More (two pointers per node)|
|Remove the last node|Slow (must iterate from the head <br>until finding the previous node for <br> properly setting its 'next' pointer)|Fast (can directly find the previous node <br> using the 'prev' pointer)|

<br>

## Arrays vs Linked Lists Comparison

|Main Aspect| Arrays |Linked Lists|
|--|--|--|
|Insert|**Costly varies linearly of O(n)** Find the relevant element and move elements in the array| **Generally cost does not vary O(1)** just insert the element at the head of the linked list for example|
|Delete|**Costly varies linearly of O(n)** Find the relevant element and move elements in the array| **Costly varies linearly of O(n)** need to iterate through the list (delete by manipulating pointers)

<br>

## <mark> Exercise to try
- Week3_DoublyLinkedList_Insert_Remove_Print_template Code on LEARN:
    - I provide a template with all the steps to implement a doubly linked list
    - Follow the code of the singly linked list from Lecture 6 – and the steps in this template to complete the functions
    - A test main is provided for you to test every function

<br>
<hr>
<br>

## Summary

### Recap
- Types of Linked Lists
    - singly: vanilla linked lists – one pointer to travel in one direction
    - doubly: two pointers to travel forward and backward
    - circularly: singly except that the tail pointer point to the head pointer
- Abstract data type 
    - collection of data items given a name, purposem and a set of funcs that op on data items
    - <mark> only necessary info is shown externally to user whule underlying detais are hidden 
    - <mark> usually implemented using class and constructors. A collection of vals is associated to private data members and a set of basic ops is associated to public member funcs

<br>

### List ADT Introduction
- list ADT is a container stucture for storing a connected sequence of data items
- basic ops
    - `insert` data into the list at a specific loc
    - `delete` removes data from the list at a given pos
    - `select` returns a val stored at an input position
    - `replace` replace a val at a given pos
    - `size` tracjs abnd returns the num of elems in list

<br>

### List ADT **Insert**
`void insert(DataType value, int position):`
1. check special cases: position zero, <mark> first , last
2. inserts val into the list at pos and incs size by 1
3. <mark> aft inserting val at pos, data is shifted towards the list end by one
4. if size reaches the max cap - the list may be inc to accommodate new elems

<br>

### List ADT: **Delete**
`void remove(int position)`
1. check special cases: position zero, first, last
2. removes data from the list at a given pos and decs size by 1
3. <mark> aft inserting the val, all of exisiting data aft postion is moved towards the list front by one
4. <mark> alternatively, use a ptr to a Node as input, Node should not previously belong to list

<br>

### List ADT: **Select**
`DataType select (int position);`
1. Check special cases: position zero, first, last
2. Returns the value stores at a given position

<br>

### List ADT: **Replace**
`void replace (int position, DataType value);`
1. Check special cases: position zero, first, last
- Replaces val stored at a given pos with *a different* value
- <mark> Alternatively, may use a pointer to a Node as input. The node should not previously belong to the list

<br>

### List ADT: **Size**
`int size ();`
1. Tracks and returns the number of elements in the list.
*Note: this is not the capacity of the list (i.e., max possible size).

<br>

### List ADT Introduction pt 2
there are two types 
- sequencial
- linked

<br>

### Squential List (Array) Implementation
- **Allocate** a <mark> contiguos <mark> block of memory to store the data, and an index is available to provide direct acess to rand data items
- keep in mind: STL a version of sequential list is provided as the <mark> < vector > library
- characterized as 4 main members
     - **index** an integer usually starting from 0
     - **data** stored as an array
     - **capacity** the max number of elements that can be stored
     - **size** the num of elems currently in the list. Any index pos exceeding the current size  does not store a valid data

<br>

### Sequencial List (Array) Implementation
- Can be implemented with
    - basic array with fixed capacity - has to be determined at the moment of designing the program, before it is run
    - dynamic array with a dynamic capacity - assign memory during runtime using any var capacity
- dynamic arrays
    - create using the new operator on the <mark> heap

<br>

### <mark> Sequential List **Initalization**

<br>

### Sequential List **Insert**
- If the size reaches capacity, capacity may be inc to accommodate new elems (dyn arrays)
- In the < vector > library, the capacity is inc on `push_back()` if out of space
- I t is important to test the validity of insert position,

<br>

### Sequential List **Delete**
*items are shifted twrds the front of the list. No gap left btwn elems

- If the size is significantly smaller than capacity, the list capacity can
be decreased
- In the < vector > library:
    - `shrink_to_fit()` can be called to try and reduce the capacity to size
    - <mark> does it doe this automaticaly
- `delete_front()` is the same as `delete(0)`
- `delete_end()` is the same as `delete(size-1)`

<br>

### Sequential List **Replace, Select and Size**
- **Select** Implemented as array lookup; 
- **Size** Implemented by returning the size val

<br>

### Linked List
- Linked list are made of: 
    - nodes which are data structures that contains:
        - data items
        - pointers to other nodes in the sequence
- singly linked list extends to implementing the doubly linked list
<br>

### Doubly Linked List
- In a doubly linked list, each node has **two pointers**
    - one pointing to the previous node
    - one pointing to the next node
- The two-way double links allow iteration to move both forwards and backwards
- A node example in a doubly linked list
<br>

### Doubly Linked List
Its implementation should keep track of the following:
- **head (or first)** pointer to the head or start of the list; <mark> set to NULL at start
- **tail (or last)** pointer to the end of the list; set to NULL at start
- **size** the number of inserted elements in the list; <mark> set to 0 at start
<br>

### Doubly Linked List **Insert**

`void insert(DataType value, int position)`
- Implemented similarly to singly List
    - just need account for the previous address (pointer)

<br>

### Doubly Linked List **Delete**
`void delete(int position)`
- Implemented similarly to singly linked list
    - <mark> it iterates in 2 ways through the list until position and removing that node

<br>

### Doubly Linked List **Replace, Select and Size**
`void replace(int position, DataType value)`
- Implemented similarly to singly linked
    - it iterates in 2 ways through the list until position and replacing its value
- `DataType select(int position)` Implemented by iterating (in 2 ways instead) through the list until position
- `int size()` Implemented by simply returning the size val

<br>

### Singly vs Doubly Linked Lists Comparison

|Aspect |Singly-linked |Doubly-linked|
|--|--|---|
|Iterate |One way |Two ways|
|Memory overhead |Less (one pointer per node)| More (two pointers per node)|
|Remove the last node|Slow (must iterate from the head <br>until finding the previous node for <br> properly setting its 'next' pointer)|Fast (can directly find the previous node <br> using the 'prev' pointer)|

<br>

### Arrays vs Linked Lists Comparison

|Main Aspect| Arrays |Linked Lists|
|--|--|--|
|Insert|**Costly varies linearly of O(n)** Find the relevant element and move elements in the array| **Generally cost does not vary O(1)** just insert the element at the head of the linked list for example|
|Delete|**Costly varies linearly of O(n)** Find the relevant element and move elements in the array| **Costly varies linearly of O(n)** need to iterate through the list (delete by manipulating pointers)

<br>

## Questions

### <mark> Exercise to try
- Week3_DoublyLinkedList_Insert_Remove_Print_template Code on LEARN:
    - I provide a template with all the steps to implement a doubly linked list
    - Follow the code of the singly linked list from Lecture 6 – and the steps in this template to complete the functions
    - A test main is provided for you to test every function
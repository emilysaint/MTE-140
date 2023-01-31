# Lecture 5 - Sequential and Linked Lists Implementation
Jan 31, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Make sure to understand pointers <br> - LRN  |- Lab <br> - start lab|

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

## List ADT Introduction
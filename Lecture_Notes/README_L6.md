# Lecture 5 - Singly Linked Lists & Other Types
Jan 26, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Make sure to understand pointers <br> - LRN  |- Lab <br> - start lab|

<br>
<hr>
<br>

## Ex1 Link list structure (Rev from Lec 5) ..DNE..
``` ruby
struct LinkedListNode {
int data; # assume all elements are ints
LinkedListNode *next;
# default constructor without parameters
LinkedListNode(): data(0), next(NULL) {};
# constructor
LinkedListNode(int x): data(x), next(NULL) {};
# ‘:’ is the constructor member initializer list used to
# initialize the class members data and next for this constructor
};
```

<br>

## Singly Linked List Structure in C++
- In C++, a struct is a class that has all members public by default; otherwise, same as class.
often used to represent data members only, without method members.
- Therefore, it is better to create a structure for the node and class for the linked list:
SLIDES AUTHORS: CA, SC, HP, II

```ruby
struct Node {
DataType data;
Node *next;
Node() : data(0), next(nullptr) {}; # it may have constructors too.
Node(int x) : data(x), next(nullptr) {};
};
```

<br>

## Class declaration
```ruby
Class LinkedList{
Private:
Node *head = nullptr; # NULL can cause ambiguity.
public:
void insert(DataType value, int position);
void replace(int position, DataType value);
void remove(int position);
void print(); # print all elements in the list
};
```

<br>
<hr>
<br>

## Summary

<br>

## Questions
- nodes
- how to listen better in lecs
    - i get so confused
    - hard to understand
    - loosing focus easily
    - not understanding one pt and the chain effect
- pin point the parts i dont understand
- Goals for the term:
    - only doing school betwen 8 - 5 studying
    - the eveings practice problems only
    - blocking off evenings for fun and weekends
    - setting schedule for working out, with consistency
    - sleep schedule 11-7pm
    - finding time to read a head and create summary notes
    - attending office hours and creating time to answer/understand questions
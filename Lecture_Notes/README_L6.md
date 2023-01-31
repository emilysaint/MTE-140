# Lecture 5 - Singly Linked Lists & Other Types
Jan 26, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Make sure to understand pointers <br> - LRN  |- Lab <br> - start lab|

<br>
<hr>
<br>

## Recap
- Basic of linked list data structire
    - contains both data items and pointer to other nodes in the sequence
    - created using dyn mem alloc - every block has it own memory basic ops

<br>
Encapsulation: putting mthds in its own func and grouping mths together in a class

<br>

## Ex Singly Linked List Structure (Ex1 from L5 build off)
- struct is a class that has all members public by default; otherwise, same as class, often to rep data members, without mthd members

Struct declaration
``` ruby
struct Node {
    DataType data;
    Node *next;
    Node() : data(0), next(nullptr) {}; # it may have constructors too.
    Node(int x) : data(x), next(nullptr) {};
};
```
Class declaration
```ruby
class LinkedList{
Private:
    Node *head = nullptr; #NULL can cause ambiguity.
public:
    void insert(DataType value, int position);
    void replace(int position, DataType value);
    void remove(int position);
    void print(); # print all elements in the list
};
```

<br>

## Inserting a New Node
Intput: **value** and **position** to insert in the list

Steps:
1. create new node to hold val to insert
2. check for specia case if the pos is zero, inser as the new head or first head and end insert <mark> here   
3. if pos is zero
    - start head
    - itterate through the links to find the node's pos=
    keep an additional pointer for the address of the previous node
4. insert the node between previous and current

Example
```ruby
void LinkedList::insert(DataType value, int
position) {
    # step 1. create new node
    Node *newNode = new Node(value);
    # step 2
    if(position == 0){
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{ //2.2 when size > 0
            newNode->next = head;
            head = newNode;
            return;
        }
    }
    # step 3
    Node *previous = head;
    Node *current = head->next;
    int i = 1;
    while (i < position) {
        previous = current;
        current = current->next;
        if (current == nullptr) {
            break; # position value invalid
        }
    i++;
    }
    # step 4
    newNode->next = current;
    previous->next = newNode;
}
```

<br>

## Replacing a Node's Value
Input: **value** and **position** to insert in the list

Steps:
1. start at the head, and itterate the list untill you find the postion
2. replace the value of that node (the adress is not touched)

*Note: no need to create a new node since we are only modifying a node's value

Example
```ruby
void LinkedList::replace(int position, DataType value) {
# step 1
    Node *current = head;
    int i = 0;
    while (i < position) {
        if (current->next == nullptr) {
            break; # reach the end
            # if this happens, it means that the position value is larger than it should be
            # by continuing the remaining code in this function,
            # the value in the tail node of the list will be replaced
        }
        current = current->next;
        i++;
    }
    # step 2
    current->data = value;
}
```

<br>

## Deleting a Node
Input: **position** to remove in the list

Steps:
1. check for special case if the position is zero, remove head
    - <mark> new head should become to the next node
    - free the current head from the memory (delete and set to *NULL* ptr)
    - end the process
2. If pos is not zero
    - start at the head itterate through the links to find the required node's pos
    - kepp and additional pointer for the address of the previous node and next node
3. <mark> remove the current node and properly link the remaining nodes
    - <mark> the previous node's address should now point to the adrress of the next node 
    - <mark> delete and free the required node at position

Example

<mark style="background-color:#cc7e78;"> 
How does it know head, where def
pointing by reference
how are you looping are you looping one behind the acc one you want
If you had made current a ptr then it would be dangling too 
</mark>

```ruby
void LinkedList::remove(int position) {
    # step 1
    if(position == 0){
        Node *temp = head; # NEED A TEMP VAR OR WHOLE ARRA WILL BE LOST
        head = head->next;
        delete temp;
        temp = nullptr;
        return;
    }
    # step 2
    Node *previous = head;
    Node *current = head->next; # CURRENT IS THE TEMP VAL 
    int i = 1;
    while (i < position) {
        if (current->next == nullptr) {
            break; # position value invalid
        }
        previous = current;
        current = current->next;
        i++;
    }
    # step 3
    previous->next = current->next;
    delete current; # DANGLING PTR
    current = nullptr;
}
```

<br>

## Printing Nodes
Steps:
1. check if list is empty to end process
2. itterate over all list until you hit the last node marked by *NULL*
    - start at the head and follow the list untill you reach the end of the list
    - cout every node val

Example
```ruby
void LinkedList::print() {
    # step 1 – you can put cout a warning here if you want
    if (head == nullptr) {
        return;
    }
    # step 2
    Node *temp = head;
    while (temp != nullptr) {
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
```

<br>

## Types of linked lists
![L6_types_linked_lists.jpg](Screenshots\L6_types_linked_lists.jpg)

singly
- starts with a ptr to the first node
- ends with a null point
- only traversed in one direction

doubly
- two *start pointers*: first elem and last elem
- allows traversals both forwards and backwards
- each node has a frwd ptr and bkwrd ptr

circularly
- ptr in the last node pts back to the first node


<br>

## Inclass Example
<mark style="background-color:#cc7e78;"> 
Draw example <br>
is interpretation correct <br>
someone asked how you would loop in rev
</mark>

```ruby
int main(){
    LinkedList myList;
    # object.comand(value, index)
    myList.Insert(2, 0);
    myList.insert(4, 1);
    myList.insert(1, 0);
    myList.insert(5, 3);
    myList.insert(3, 2);
    myList.print();
    myList.replace(2, 33);
    # myList.print();
    myList.remove(3):
    myList.remove(0);
    # myList.print();
    return 0;
}
```


<br>
<hr>
<br>

## Summary

### Recap
- Basic of linked list data structire
    - contains both data items and pointer to other nodes in the sequence
    - created using dyn mem alloc - every block has it own memory basic ops

<br>
Encapsulation: putting mthds in its own func and grouping mths together in a class

<br>

### Ex Singly Linked List Structure (Ex1 from L5 build off)
- struct is a class that has all members public by default; otherwise, same as class, often to rep data members, without mthd members

<br>

### Inserting a New Node
Intput: **value** and **position** to insert in the list

Steps:
1. create new node to hold val to insert
2. check for specia case if the pos is zero, inser as the new head or first head and end insert <mark> here   
3. if pos is zero
    - start head
    - itterate through the links to find the node's pos=
    keep an additional pointer for the address of the previous node
4. insert the node between previous and current

<br>

### Replacing a Node's Value
Input: **value** and **position** to insert in the list

Steps:
1. start at the head, and itterate the list untill you find the postion
2. replace the value of that node (the adress is not touched)

*Note: no need to create a new node since we are only modifying a node's value

<br>

### Deleting a Node
Input: **position** to remove in the list

Steps:
1. check for special case if the position is zero, remove head
    - <mark> new head should become to the next node
    - free the current head from the memory (delete and set to *NULL* ptr)
    - end the process
2. If pos is not zero
    - start at the head itterate through the links to find the required node's pos
    - kepp and additional pointer for the address of the previous node and next node
3. <mark> remove the current node and properly link the remaining nodes
    - <mark> the previous node's address should now point to the adrress of the next node 
    - <mark> delete and free the required node at position

<br>

### Printing Nodes
Steps:
1. check if list is empty to end process
2. itterate over all list until you hit the last node marked by *NULL*
    - start at the head and follow the list untill you reach the end of the list
    - cout every node val

<br>

### Types of linked lists

singly
- starts with a ptr to the first node
- ends with a null point
- only traversed in one direction

doubly
- two *start pointers*: first elem and last elem
- allows traversals both forwards and backwards
- each node has a frwd ptr and bkwrd ptr

circularly
- ptr in the last node pts back to the first node
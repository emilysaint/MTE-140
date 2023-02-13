Consider the following pseudocode that is executed on a sequential implementation of a List ADT. 
Indexes start from 0. 

After this code is run, what would be the first three values store in the list? 

Each element includes data of char type, and to indicate empty space, use # symbol. 

You can assume that the list is empty at first. 

In your answers, just write the character without any other symbols. 

For example for 's' just answer s in the blank. For '3' just answer 3 in the blank.

insert('s', 0);
insert('y', 0);
insert('d', 1);
delete(2);
insert('e', 0);
delete(1);
insert('2', 2);
replace(1, '2');
insert('3', 0);
delete(1);

///

Consider the following code fragment that is executed on a singly linked implementation of List ADT. 
LinkedList includes Node* first and int size. 
Node includes int data and Node* next.

LinkedList* list = new LinkedList(); // creates a new list
list->insert_front(41); // inserts a node at the front
list->insert_back(42); // inserts a node at the back
list->insert_front(44);
list->insert(43, 2) // inserts a node at the specified index. The first input value is the data. The second input value is the index. Indexes start from 0.

illustrate what happens after this code is run by putting the proper value at the places of A, B, C, and D.


//

Consider the following code fragment that is executed on a doubly linked implementation of List ADT. 
DoublyLinkedList includes DLLNode* first, DLLNode* last, and int size. 
DLLNode includes int data, DLLNode* next, and DLLNode* prev.

DoublyLinkedList* list = new DoublyLinkedList(); // creates a new list
list->insert_front(17); // inserts node at the front
list->insert_front(32);
list->insert(9, 4); // inserts node at the specified index. The first input number value is the data. The second input number value is the index. Indexes start from 0.
list->insert_back(8); // inserts node at the back/tail

In the diagram below, illustrate what happens after this code is run by putting the proper value at the places of of A, B, and C. 
Assume that list contiguousness is preserved, which means that insert functions will reject insertion attempts at invalid indexes.

...

Continuing after the previous steps, the following code is executed.
list->insert_back(45);
list->replace(1, 19); // replace item at index 1 with value 19
list->remove_back(); // delete node from the back
list->remove_front(); // delete node from the front

In the diagram below, illustrate what happens after this code is run by putting the proper value at the places of A and B.


//

Consider the following function that takes the address of the head of a Doubly Linked List as the parameter. 
Assume that a node of doubly linked list has previous pointer as prev and next pointer as next.
 
void test(struct node **head_ref)
{
    struct node *temp = NULL;
    struct node *current = *head_ref;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        }
    if(temp != NULL )
    *head_ref = temp->prev;
}
 
Assume that the address of the head of following doubly linked list is passed to above function 
1 <--> 2 <--> 3 <--> 4 <--> 5 <-->6. 

What should be the modified linked list after the function call?
2 <--> 1 <--> 4 <--> 3 <--> 6 <--> 5
5 <--> 4 <--> 3 <--> 2 <--> 1 <--> 6
** 6 <--> 5 <--> 4 <--> 3 <--> 2 <--> 1 **
6 <--> 5 <--> 4 <--> 3 <--> 1 <--> 2

//

Which one of these statements is true about the following code?

int test(int n)
{
    if (n>0){
        return n + test(n-1);
    }
    return 0;
}

Question 5 options:

The base case for this recursive function is an argument with the value zero.


The base case for this recursive method is an argument with any value which is greater than zero


There is no base case.


The base case for this recursive method is an argument with any value which is less than or equal to zero

// Recursion happens when an algorithm does not use a loop.

// A solution to a 64-disk Towers of Hanoi problem requires at least how many moves to complete?
264-1

// Consider the following code snippet:
void my_recursive_function()
{
    my_recursive_function();    
}

int main()
{
    my_recursive_function();
    return 0;
}
What will happen when the above snippet is executed?

///


Consider the following code fragment that is executed on a singly linked implementation of List ADT. 
The Linked List includes Node* head and Node includes string data and Node* next.

// test(head, 2, "Charbel")

void test(Node*& head, int index, string value) {

    if (index == 0) {

        head = new Node(value, head);

    } else {

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {

            temp = temp->next;

        }

        temp->next = new Node(value, temp->next);

    }

Assume that we passed test(head, 2, "Charbel") for following singly linked list is passed to above function "Austin" --> "Carl" --> "Elahe". 
What should be the modified linked list after the function call?
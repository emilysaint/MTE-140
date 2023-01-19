# Lecture 3
# C++ Implementation of Pointers
Jan 19, 2023

## To Dos
- Make sure to understand pointers
- Lab

<br>

Classes and ojects and DS Implementations

<br>

## Classes and Objects
A class reps a kind of oject
creating instances specific objects
it has members (attributes) and mths
an oject represents and indiv and specific item it is an instance of the general class

<br>

## Ex 1: Dealer Inventory Practice
Info needed, make, model, year, 

SD is a group of data intems
- each car is a data item
    - diff types, colours  (attributes)
- each data item has mths to operate on it
    - mthds/functions, add, print, etc

<br>

Struct
```
struct Car{
    // all members are public by defults
    int year; 
    string brand; 
    double price; 
};
```
Classes
schould not return anythig
```
class CarRecord{
    // all members are private by default
    Car carinventory[100];
    int size = 0;

public:
    // no return anything
    // someone asked about mal practice changes in two places ?
    void addCar (int year, string, brand, double price);
    void printAll(); //? void?
    }
}
```
In header? in class bad habit - incapsulation
this is private
functions go in header
incapsulations - accesss to everything
```
void CarRecord::addCar(int year, string brand, double price){
        carinventory[size].year= year; 
        carinventory[size].brand = brand; 
        carinventory[size].price = price; 
        size++; 
void CarRecord::printAll(){
    for (int i= 0; i<size, i++){
        cout << "Car #" << i << carinventory[i].year << ":" << carinventory[i].brand << ":" << carinventory[i].price ; 
    }
}
```
Main
```
int main(){
    CarRecord inventory;
    // add car 1
    inentort.addCar(2002, "Honda", 1000.00)
    inventory.printAll()
    return 0; 
}
```

Output
```
>> Car #0: 2002 Honda, price
...
```

<br>

## Pointers
Definition: is a var that stores the memory address of another var. 
A pointer "points to" thet vars address
- like a storage unit number

<br>

## General info
Pointers: can story any data type

Declaring a pointer with an askterick *
int *ip; 
- ip is declared as a pointer to an int var

Address operator "*&*" (address-of-operator
used to det the adress of a var 

Dereference operator
acesses the value of
used to folloe the [pointer to its target
getting ip to give "25"

```
int *ip; 
int iv1 = 25; 
ip = &iv1; 
// print int stored in var
cout << iv1;
// print memory address
cout << ip; 
// dereferncing operand
cout << *ip;
```
Output
```
>> 25
>> 1776
>> 25
```

<br>

## Ex 2 Copying Pointers
pointer always points to the adress
![L3_pointers_ex2.jpg](Screenshots/L3_pointers_ex2.jpg)

<br>

## Pointers to Pointers (I dont understand)
Since a pointer itself is stored somewhere in the memory its also hat its own memory address
```
int iv1 = 25
// ip1 holds the address of x 
int *ip1 = &iv1;
// ip2 holds the adress of io1 (ip1 its ownadres) ip2 is acturally declared **ip2 bc it hold the address of a pointer that holds the adress of another odject
int *ip2 = &ip1; 
```
ip2 is a ponter to a pointer (**)
```
int **ip2; 
ip2 = &ip1; 
```
![L3_pointers_to_pointers.JPG](Screenshots/L3_pointers_to_pointers.JPG)

<br>

## Ex 2.b (Make sure to understand) Rewrite code
Main code
![L3_ex2.b_img1_.JPG](Screenshots/L3_ex2.b_img1_.JPG)
Output
![L3_ex2.b_img2_.JPG](Screenshots/L3_ex2.b_img2_.JPG)
edit!! ..nA...

terminating code resets

<br>

## Why do we use Pointers?
- support datda - linked lists
- function manipulation to the input var
- direct memory access and manipulation

<br>

## Questions
- classes refresher
- structure of creating a class
- public and private uses and otimization
- header file etc, and cpp organization
- Ex 1
    - class question mal prac
    - set at 100 or add untill 100 etc?
    - do we have to add a return 0 in all main
    - struct
- Dynamic memory vs static memory allocation
# Lecture 3
# C++ Implementation of Pointers
Jan 19, 2023

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
```
int *ip; 
int iv1 = 25; 
ip = &iv1; 
cout << iv1;
cout << ip; 
```
Output
```
>> 25
>> 1776
```

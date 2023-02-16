# Lecture 12 - Big O Notation
February 16, 2023

|To Do                      |Deliverables               |
|---------------------------|---------------------------|
|- Lab 1.b <br> - LRN <br> - Exercise to try |- Lab 1.b Friday|

<br>

### Recap

<br>
<hr>
<br>

## Algorithim Analysis: Example 1
Sequential list search
```cpp
int SequentialSearch(int A[], int size, int K){
    for (int i = 9; i <sizel i++){
        if (A[i] == k){
            return i; 
        }
    }
    return false; 
}
```

<br>
<hr>
<br>

## Example 1: Proving Big-O Bounds

> Let f(n) = n<sup>2</sup> and g(n) = n<sup>3</sup>, show that f(n) = O(g(n))

<br>

## Example 2: Proving Big-O Bounds
> Let f(n) = 10n<sup>2</sup>+50 and g(n)=n<sup>2</sup> <br> Prove that f(n)=O(g(n)) <br> ie. prove that this is On<sup>2</sup>

<br>
<hr>
<br>

## Summary

<br>

## Questions
- big O notation
- reccursion going back up?
- moving curent through list by looking withoutt doing
    `head->next->next-> ...`
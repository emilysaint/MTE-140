/*======================================================================
** You can use this file to test if your code is working
** properly by designing your own test case and test code.
**
** You are allowed to modify this file as much as you would like.
** For grading, we will use our own filled version.
**======================================================================*/

#include <iostream>
#include <string>

#include "circular-queue.h"
#include "dynamic-stack.h"

using namespace std;

// Assert Macros for test cases.
#define ASSERT_TRUE(T) \
    if (!(T))          \
        return false;
#define ASSERT_FALSE(T) \
    if ((T))            \
        return false;

string get_status_str(bool status) {
    return status ? "PASSED" : "FAILED";
}

// Define the test suites (implementation below).
class DynamicStackTest {
private:
    bool test_result[10] = {0,0,0,0,0,0,0,0,0,0};
    string test_description[10] = {
            "Test1: new empty stack is valid",
            "Test2: push() an element on zero-element stacks",
            "Test3: peek() and pop() on one-element stack",
            "Test4: peek(), push(), and pop() work properly together",
            "Test5: push() too many elements should increase capacity",
            "Test6: push() keeps changing size and capacity",
            "Test7: pop() keeps changing size and capacity",
            "Test8: try to pop() too many elements, then push() a few elements",
            "Test9: lots of push() and pop(), all of them valid",
            "Test10: lots of push() and pop(), some of them invalid"
    };

public:
    string getTestDescription(int test_num);
    void runAllTests();
    void printReport();

    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();
    bool test9();
    bool test10();
};

class CircularQueueTest {
private:
    bool test_result[10] = {0,0,0,0,0,0,0,0,0,0};
    string test_description[10] = {
            "Test1: new empty queue is valid",
            "Test2: enqueue() an element on zero-element queues",
            "Test3: peek() and dequeue() on one-element queue",
            "Test4: peek(), enqueue(), and dequeue() work properly together",
            "Test5: enqueue() too many elements should fail",
            "Test6: enqueue() keeps changing tail",
            "Test7: dequeue() keeps changing head",
            "Test8: try to dequeue() too many elements, then enqueue() a few elements",
            "Test9: lots of enqueue() and dequeue(), all of them valid",
            "Test10: lots of enqueue() and dequeue(), some of them invalid"
    };

public:
    string getTestDescription(int test_num);
    void runAllTests();
    void printReport();

    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();
    bool test9();
    bool test10();
};


//======================================================================
//================================ MAIN ================================
//======================================================================
int main() {

    // The test suite has some tests implemented for you,
    // and place holders for where you can put your own.
    DynamicStackTest ds_test;

    // You can check the description for each test to see
    // what we will be testing for with the following method.
    // Alternatively, you can also navigate to the line above
    // where the test description is stored to read it.
    cout << ds_test.getTestDescription(1) << endl;

    // Tests can be run one at a time to get their result
    bool result = ds_test.test1();
    cout << "Test1: " << get_status_str(result) << endl << endl;

    // Or you can run all of the tests at once and generate a report.
    ds_test.runAllTests();
    ds_test.printReport();

    // Uncomment and use this for lab 2.2 when it is released.
    CircularQueueTest cq_test;
    cq_test.runAllTests();
    cq_test.printReport();

    return 0;
}


//======================================================================
//========================= Dynamic Stack Test =========================
//======================================================================
string DynamicStackTest::getTestDescription(int test_num) {
    if (test_num < 1 || test_num > 10) { // check range.
        return "";
    }
    return test_description[test_num-1];
}

void DynamicStackTest::runAllTests() {
    test_result[0] = test1();
    test_result[1] = test2();
    test_result[2] = test3();
    test_result[3] = test4();
    test_result[4] = test5();
    test_result[5] = test6();
    test_result[6] = test7();
    test_result[7] = test8();
    test_result[8] = test9();
    test_result[9] = test10();
}

void DynamicStackTest::printReport() {
    cout << "  DYNAMIC STACK TEST RESULTS  \n"
         << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n";
    for (int idx = 0; idx < 10; ++idx) {
        cout << test_description[idx] << "\n  " << get_status_str(test_result[idx]) << endl << endl;
    }
    cout << endl;
}

// Test 1: new empty stack is valid
bool DynamicStackTest::test1() {

    // Test set up.
    unsigned int capacity = 5;
    DynamicStack stack(capacity);

    // Check that the internal state is set correctly.
    ASSERT_TRUE(stack.size() == 0)
    ASSERT_TRUE(stack.empty())
    ASSERT_TRUE(stack.capacity_ == capacity)
    ASSERT_TRUE(stack.init_capacity_ == capacity)
    ASSERT_FALSE(stack.items_ == nullptr)

    // Test the default constructor for the stack.
    DynamicStack default_stack;

    // Check that the internal state is set correctly.
    ASSERT_TRUE(default_stack.size() == 0)
    ASSERT_TRUE(default_stack.empty())
    ASSERT_TRUE(default_stack.capacity_ == 16)
    ASSERT_TRUE(default_stack.init_capacity_ == 16)
    ASSERT_FALSE(default_stack.items_ == nullptr)

    // Return true to signal all tests passed.
    return true;
}

// Test 2: push() an element on zero-element stacks
bool DynamicStackTest::test2() {

    // Test set up.
    unsigned int capacity = 5;
    DynamicStack stack(capacity);

    // Try to add data to the stack (returns void so no assert check for success).
    stack.push(100);

    // Check that the internal state is correct.
    ASSERT_TRUE(stack.size() == 1)
    ASSERT_TRUE(stack.capacity_ == capacity)
    ASSERT_TRUE(stack.init_capacity_ == capacity)
    ASSERT_FALSE(stack.items_ == nullptr)
    ASSERT_TRUE(stack.items_[0] == 100)

    // Return true to signal all tests passed.
    return true;
}

// Test 3: peek() and pop() on one-element stack
bool DynamicStackTest::test3() {

    // Test set up.
    unsigned int capacity = 5;
    DynamicStack stack1(capacity);
    DynamicStack stack2(capacity);

    // Check peek on an empty stack.
    ASSERT_TRUE(stack1.peek() == DynamicStack::EMPTY_STACK)

    // Try to add data to the stacks (returns void so no assert check for success).
    stack1.push(100);
    stack2.push(200);

    // Check the state of the capacities before popping.
    //cout << "1" << endl;
    ASSERT_TRUE(stack1.init_capacity_ == 5 && stack1.capacity_ == 5 && !stack1.empty() && stack1.size_ == 1)
    //cout << "2" << endl;
    ASSERT_TRUE(stack2.init_capacity_ == 5 && stack2.capacity_ == 5 && !stack2.empty() && stack2.size_ == 1)

    // Peek at the top element, then remove it.
    //cout << "3" << endl;
    ASSERT_TRUE(stack1.peek() == 100 && stack1.pop() == 100)
    //cout << "4" << endl;
    ASSERT_TRUE(stack2.peek() == 200 && stack2.pop() == 200)

    // Check the state of the capacities after popping.
    //cout << "5" << endl;
    ASSERT_TRUE(stack1.init_capacity_ == 5 && stack1.capacity_ == 5 && stack1.empty() && stack1.size_ == 0)
    //cout << "6" << endl;
    ASSERT_TRUE(stack2.init_capacity_ == 5 && stack2.capacity_ == 5 && stack2.empty() && stack2.size_ == 0)

    // Check that the peek on an empty stack still gives expected value.
    //cout << "7" << endl;
    ASSERT_TRUE(stack2.peek() == DynamicStack::EMPTY_STACK)

    // Return true to signal all tests passed.
    return true;
}

// Test 4: peek(), push(), and pop() work properly together
bool DynamicStackTest::test4() {
    // Test set up.
    unsigned int capacity = 100;
    DynamicStack stack(capacity);
//    stack.print();
    for (int i = 0; i < 100; i++) {
        stack.push(i);
        ASSERT_TRUE(stack.peek() == i);
    }
//    stack.print();
    for (int i = 99; i > -1; --i){
        ASSERT_TRUE(stack.peek() == i);
        ASSERT_TRUE(stack.pop() == i);
    }

    // Implement a test case which does the above description.
    return true;
}

// Test 5: push() too many elements should increase capacity
bool DynamicStackTest::test5() {
    // Test set up.
    unsigned int capacity = 2;
    DynamicStack stack(capacity);

    // Push three elements onto the stack.
    int j = 2;
    for (int i = 0; i < 512; i++) {
        if (j == i) {
            ASSERT_TRUE(stack.capacity_ == j);
            ASSERT_TRUE(stack.size_ == i);
        }
        if (j < i) j *= 2;

        stack.push(i);
    }

    return true;
}

// Test 6: push() keeps changing size and capacity
bool DynamicStackTest::test6() {

    // Test set up.
    unsigned int capacity = 3;
    DynamicStack stack(capacity);

    // Push three elements onto the stack.
    for (int i = 0; i < 3; i++) {
        stack.push(i);
    }

    // Check the resulting capacity.
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 3 && stack.size_ == 3)

    // Try adding more elements onto the "at capacity" stack.
    for (int i = 3; i < 6; i++) {
        stack.push(i);
    }

    // Check that the capacity has dynamically changed to the correct value.
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 6 && stack.size_ == 6)

    // Add more.
    for (int i = 6; i < 9; i++) {
        stack.push(i);
    }

    // Check that new capacity.
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 12 && stack.size_ == 9)

    // Return true to signal all tests passed.
    return true;
}

// Test 7: pop() keeps changing size and capacity
bool DynamicStackTest::test7() {
    // Test set up.
    unsigned int capacity = 3;
    DynamicStack stack(capacity);

    // Push three elements onto the stack.
    for (int i = 0; i < 3; i++) {
        stack.push(i);
    }

    // Check the resulting capacity.
    cout << "1" << endl;
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 3 && stack.size_ == 3)

    // Try adding more elements onto the "at capacity" stack.
    for (int i = 3; i < 6; i++) {
        stack.push(i);
    }

    // Check that the capacity has dynamically changed to the correct value.
    cout << "2" << endl;
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 6 && stack.size_ == 6)

    // Add more.
    for (int i = 6; i < 9; i++) {
        stack.push(i);
    }

    // Check that new capacity.
    cout << "3" << endl;
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 12 && stack.size_ == 9)

    for (int i = 0; i < 6; ++i){
        stack.pop();
    }

    cout << "4" << endl;
    cout << "init_capacity_ " << stack.init_capacity_ << endl;
    cout << "stack.capacity_ " << stack.capacity_ << endl;
    cout << "stack.size_ " << stack.size_ << endl;
    ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 6 && stack.size_ == 3)
    // Return true to signal all tests passed.
    return true;
}

// Test 8: try to pop() too many elements, then push() a few elements
bool DynamicStackTest::test8() {
    // Test set up.
    unsigned int capacity = 3;
    DynamicStack stack(capacity);

    // Push three elements onto the stack.
    for (int i = 0; i < 3; i++) {
        stack.push(i);
    }

    stack.pop();
    stack.pop();
    stack.pop();
    ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK);
    ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK);

    for (int i = 0; i < 50; i++) {
        stack.push(i);
    }

    ASSERT_TRUE(stack.peek() == 49);
    ASSERT_TRUE(stack.pop() == 49);

    // Implement a test case which does the above description.
    return true;
}

// Test 9: lots of push() and pop(), all of them valid
bool DynamicStackTest::test9() {
    // Test set up.
    unsigned int capacity = 3;
    DynamicStack stack(capacity);

    // Push three elements onto the stack.
    for (int i = 0; i < 3; i++) {
        stack.push(i);
    }

    stack.push(3);
    ASSERT_TRUE(stack.peek() == 3);
    stack.push(4);
    ASSERT_TRUE(stack.peek() == 4);
    ASSERT_TRUE(stack.pop() == 4);
    ASSERT_TRUE(stack.pop() == 3);
    ASSERT_TRUE(stack.pop() == 2);
    ASSERT_TRUE(stack.pop() == 1);
    ASSERT_TRUE(stack.pop() == 0);

    return true;
}

// Test 10: lots of push() and pop(), some of them invalid
bool DynamicStackTest::test10() {
    // Test set up.
    unsigned int capacity = 10;
    DynamicStack stack(capacity);

    // Push elements onto the stack.
    for (int i = 0; i < capacity; i++) {
        stack.push(i);
    }
    for (int i = 0; i < capacity; i++) {
        ASSERT_TRUE(stack.pop() == capacity - 1 - i)
    }
    ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
    stack.push(123);
    ASSERT_TRUE(stack.pop() == 123)
    ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
    stack.push(42);
    ASSERT_FALSE(stack.pop() == DynamicStack::EMPTY_STACK)
    ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)

    return true;
}

//======================================================================
//======================== Circular Queue Test =========================
//======================================================================
string CircularQueueTest::getTestDescription(int test_num) {
    if (test_num < 1 || test_num > 10) { // check range.
        return "";
    }
    return test_description[test_num-1];
}

void CircularQueueTest::runAllTests() {
    test_result[0] = test1();
    test_result[1] = test2();
    test_result[2] = test3();
    test_result[3] = test4();
    test_result[4] = test5();
    test_result[5] = test6();
    test_result[6] = test7();
    test_result[7] = test8();
    test_result[8] = test9();
    test_result[9] = test10();
}

void CircularQueueTest::printReport() {
    cout << "  CIRCULAR QUEUE TEST RESULTS  \n"
         << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n";
    for (int idx = 0; idx < 10; ++idx) {
        cout << test_description[idx] << "\n  " << get_status_str(test_result[idx]) << endl << endl;
    }
    cout << endl;
}

// Test 1: new empty queue is valid
bool CircularQueueTest::test1() {

    // Test set up.
    unsigned int capacity = 5;
    CircularQueue queue(capacity);

    // Check that the internal state is set correctly.
    ASSERT_TRUE(queue.size() == 0)
    ASSERT_TRUE(queue.empty())
    ASSERT_FALSE(queue.full())
    ASSERT_TRUE(queue.capacity_ == capacity)
    ASSERT_FALSE(queue.items_ == nullptr)
    ASSERT_TRUE(queue.head_ == 0 && queue.tail_ == 0)

    // Test the default constructor for the queue.
    CircularQueue default_queue;

    // Check that the internal state is set correctly.
    ASSERT_TRUE(default_queue.size() == 0)
    ASSERT_TRUE(default_queue.empty())
    ASSERT_FALSE(default_queue.full())
    ASSERT_TRUE(default_queue.capacity_ == 16)
    ASSERT_FALSE(default_queue.items_ == nullptr)
    ASSERT_TRUE(default_queue.head_ == 0 && default_queue.tail_ == 0)

    // Return true to signal all tests passed.
    return true;
}

// Test 2: enqueue() an element on zero-element queues
bool CircularQueueTest::test2() {

    // Test set up.
    unsigned int capacity = 5;
    CircularQueue queue1(capacity);
    CircularQueue queue2(capacity);

    // Try to enqueue data to the queues.
    ASSERT_TRUE(queue1.enqueue(100))
    ASSERT_TRUE(queue2.enqueue(100))

    // Check that the internal state is correct.
    ASSERT_TRUE(queue1.size() == queue2.size() && queue1.size() == 1)
    ASSERT_FALSE(queue1.items_ == nullptr)
    ASSERT_FALSE(queue2.items_ == nullptr)
    ASSERT_TRUE(queue1.items_[queue1.head_] == 100)
    ASSERT_TRUE(queue2.items_[queue2.head_] == 100)
    ASSERT_TRUE(queue1.head_ == 0 && queue1.tail_ == 1)
    ASSERT_TRUE(queue2.head_ == 0 && queue2.tail_ == 1)

    // Return true to signal all tests passed.
    return true;
}

// Test 3: peek() and dequeue() on one-element queue
bool CircularQueueTest::test3() {

    // Test set up.
    unsigned int capacity = 5;
    CircularQueue queue1(capacity);
    CircularQueue queue2(capacity);

    // Check peek on an empty queue.
    ASSERT_TRUE(queue1.peek() == CircularQueue::EMPTY_QUEUE)

    // Add data to the queues.
    ASSERT_TRUE(queue1.enqueue(100))
    ASSERT_TRUE(queue2.enqueue(200))

    // Peek at the top element, then remove it.
    ASSERT_TRUE(queue1.peek() == 100 && queue1.dequeue() == 100)
    ASSERT_TRUE(queue2.peek() == 200 && queue2.dequeue() == 200)

    // Check the resulting sizes of the queues.
    ASSERT_TRUE(queue1.size_ == queue2.size_ && queue1.size_ == 0)
    ASSERT_TRUE(queue1.empty() && queue2.empty())

    // Check that the peek on an empty queue still gives expected value.
    ASSERT_TRUE(queue2.peek() == CircularQueue::EMPTY_QUEUE)

    // Return true to signal all tests passed.
    return true;
}

// Test 4: peek(), enqueue(), and dequeue() work properly together
bool CircularQueueTest::test4() {
    // Implement a test case which does the above description.
    return false;
}

// Test 5: enqueue() too many elements should fail
bool CircularQueueTest::test5() {
    // Implement a test case which does the above description.
    return false;
}

// Test 6: enqueue() keeps changing tail
bool CircularQueueTest::test6() {
    // Implement a test case which does the above description.
    return false;
}

// Test 7: dequeue() keeps changing head
bool CircularQueueTest::test7() {

    // Test set up.
    unsigned int capacity = 5;
    CircularQueue queue(capacity);

    // Add some data.
    for (unsigned int i = 0; i < capacity; i++) {
        ASSERT_TRUE(queue.enqueue(i))
    }

    // Check that the head holds the correct item, then remove it.
    // Check that the size reflects the change made.
    for (unsigned int i = 0; i < capacity; i++) {
        ASSERT_TRUE(queue.items_[queue.head_] == i && queue.dequeue() == i)
        ASSERT_TRUE(queue.size_ == (capacity - i - 1))
    }

    // Return true to signal all tests passed.
    return true;
}

// Test 8: try to dequeue() too many elements, then enqueue() a few elements
bool CircularQueueTest::test8() {
    // Implement a test case which does the above description.
    return false;
}

// Test 9: lots of enqueue() and dequeue(), all of them valid
bool CircularQueueTest::test9() {
    // Implement a test case which does the above description.
    return false;
}

// Test 10: lots of enqueue() and dequeue(), some of them invalid
bool CircularQueueTest::test10() {
    // Implement a test case which does the above description.
    return false;
}
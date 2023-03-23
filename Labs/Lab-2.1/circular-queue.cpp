#include "circular-queue.h"

/* FINAL Notes 
15 MC
10 fill
3 full questions
50% trees
*/

// https://www.programiz.com/dsa/circular-queue#:~:text=A%20circular%20queue%20is%20the,forming%20a%20circle%2Dlike%20structure.&text=The%20circular%20queue%20solves%20the,be%20non%2Dusable%20empty%20space.
// https://www.simplilearn.com/tutorials/data-structure-tutorial/circular-queue-in-data-structure 
// https://www.geeksforgeeks.org/introduction-and-array-implementation-of-circular-queue/
// https://www.javatpoint.com/circular-queue

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    items_ = new CircularQueue[16];
    capacity_ = 16;
    size_ = 0;
    int head_, tail_; // how come no ptr
}

CircularQueue::CircularQueue(unsigned int capacity) {
    items_ = new CircularQueue[capacity];
    capacity_ = capacity;
    size_ = 0;
    int head_, tail_; 
}

CircularQueue::~CircularQueue() {
    delete[] items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
    return size_; 
}

bool CircularQueue::empty() const {
    if (size_ <=0){
        return true;  
    } 
    return false;
}

bool CircularQueue::full() const {
    if (size_ == capacity_){
        return true;
        }
    return false;
}

CircularQueue::QueueItem CircularQueue::peek() const { // how does the syntax of this change this 
    if((size_ > capacity_ && size_<= 0){  
        return false; 
    }  
    CircularQueue::EMPTY_QUEUE : items_[head_]; // look ing at head or tail, what is this syntax why not just return
}

// Adding an element
bool CircularQueue::enqueue(QueueItem value) {
    // Is full or invalid size
    if ((size_<0) || (size_ >= capacity_) || ((item_[tail_] + 1)%EMPTY_QUEUE = items_[head_]){
        return false; 
    }
 
    // Is empty
    else if (items_[head_] == NULL || items_[tail_] = NULL){
        items_[head_] = value; 
        return true;    
    }

    else if (items_[tail_] = EMPTY_QUEUE - 1 && items_[head_]!= 0){
        items_[tail_] = value; 
        return true; 
    }

    else{
        items_[tail_] = (items_[tail_++])%capacity_;  /// mod cap
        items_[tail_] = value;
        size_ ++; 
        return true;
    }
}

// Removing an element
CircularQueue::QueueItem CircularQueue::dequeue() { // how does the syntax of this change this
    // If invalid size 
    if ((size_<0) || (size_ > capacity_)){
        return CircularQueue::EMPTY_QUEUE;
    }

    // If empty
    else if (items_[head_] == NULL || items_[tail_] = NULL){
        return false;
    }

    // Step 3: Set Element = Queue[Front]
    QueueItem value = items_[head_]; // why not null why syntax

    // Step 4: If there is only one element in a queue, 
    // set both Front and Rear to -1 
    // (IF Front = Rear, set Front = Rear = -1)
    if (items_[head_] == items_[tail_]){
        items_[head_] = NULL;
        items_[tail_] = NULL;
    }

    // Step 5: And if Front = Maxsize -1 set Front = 0
    else if (items_[head_] == size_-1){
        items_[head_] = 0;
    }
        
    // Step 6: Otherwise, set Front = Front + 1
    else{
        items_[head_++] = (items_[head_++])%capacity_ // what does this mean
        items_[head_] = value; // what does this mean
        size_--; 
    }
    return value;
}

void CircularQueue::print() const { 
    if(((items_[head_] == NULL) && (items_[tail_]==NULL)) || (size_<0) || (size_ > capacity_)){  
        std::cout << "List invalid or empty" << std::endl;
    }  

    else{  
        for (int i, i<size_; i++)  
        {  
            std::cout << items_[head_+i] <<  std::end; 
        }  
    }  
}

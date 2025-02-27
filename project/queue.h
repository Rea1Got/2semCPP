#ifndef QUEUE_H 
#define QUEUE_H

#include <vector>
#include <stdexcept>

struct Queue {
    std::vector<int> data; 
    int head;              
    int tail;              
    int capacity;           

    Queue(int size); 

    bool isEmpty() const; 

    bool isFull() const; 

    void enqueue(int value);

    int dequeue(); 

    int size() const;
};


#endif 


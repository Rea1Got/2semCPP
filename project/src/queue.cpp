#include "queue.h"

// Constructor
Queue::Queue(int size) : head(0), tail(0), capacity(size) {
    data.resize(size);
}

bool Queue::isEmpty() const {
    return head == tail;
}

bool Queue::isFull() const {
    return (tail + 1) % capacity == head;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        throw std::overflow_error("Error! Queue is full.");
    }
    data.array[tail] = value;
    tail = (tail + 1) % capacity; 
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Error! Queue is empty.");
    }
    int value = data.array[head];
    head = (head + 1) % capacity;
    return value;
}

int Queue::size() const {
    return (tail - head + capacity) % capacity;
}


#include <vector>
#include <stdexcept>


struct Queue {
    std::vector<int> data; 
    int head;              
    int tail;              
    int capacity;           

    // constructor
    Queue(int size) : head(0), tail(0), capacity(size) {
        data.resize(size);
    }

    bool isEmpty() const {
        return head == tail;
    }

    bool isFull() const {
        return (tail + 1) % capacity == head;
    }

    void enqueue(int value) {
        if (isFull()) {
            throw std::overflow_error("Очередь полна!");
        }
        data[tail] = value;
        tail = (tail + 1) % capacity; 
    }

    int dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Очередь пуста!");
        }
        int value = data[head];
        head = (head + 1) % capacity;
        return value;
    }

    int size() const {
        return (tail - head + capacity) % capacity;
    }
};

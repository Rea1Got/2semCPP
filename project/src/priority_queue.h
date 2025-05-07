#ifndef PRIORITY_QUEUE_H 
#define PRIORITY_QUEUE_H

#include <stdexcept>
#include "dynamic_array.h"

struct BinaryHeap{
    DynamicArray data;  // (vertex, distance) 

    BinaryHeap(int init_capacity = 10);
                                           
    int parent(int i);
    int left(int i);
    int right(int i);

    void swap(int first, int second);
    bool compare(int first, int second);
    void heapify(int i);

    bool isEmpty();
    int getSize();
    void insert(int vertex, int distance);
    DynamicArray extractRoot();

};

#endif 
 

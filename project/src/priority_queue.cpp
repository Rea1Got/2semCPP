#include "priority_queue.h"
#include <iostream>
#include <cassert>

int BinaryHeap::parent(int i) { return (i-1) / 2; }
int BinaryHeap::left(int i) { 
    int l = 2*i + 1;
    std::cerr << "left " << l << " with i = " << i << " and datasize " << data.size << std::endl;
    return l; 
}
int BinaryHeap::right(int i) {
    int r = 2*i + 2;
    std::cerr << "right " << r << " with i = " << i << " and datasize " << data.size << std::endl;
    return r; 
}



void BinaryHeap::swap(int i, int j){
    std::swap(data.array[i*2], data.array[j*2]);
    std::swap(data.array[i*2 + 1], data.array[j*2 + 1]);
}

bool BinaryHeap::compare(int i, int j){
    return data.array[i*2 + 1] < data.array[j*2 + 1]; // min-Heap
}

void BinaryHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    // std::cerr << "Heapifying i: " << i << ", l: " << l << ", r: " << r << ", smallest: " << smallest << std::endl;

    if (l < data.size and compare(l, smallest)){
        smallest = l;
        // std::cerr << "Smallest updated to l: " << l << std::endl;
    }

    if (r < data.size and compare(r, smallest)){
        smallest = r;
        // std::cerr << "Smallest updated to r: " << r << std::endl;
    }

    if (smallest != i){
        // std::cerr << "Swapping i: " << i << " and smallest: " << smallest << std::endl;
        swap(i, smallest);
        heapify(smallest);
    }
}

BinaryHeap::BinaryHeap(int init_capacity) {
    data = DynamicArray();
    data.resize(init_capacity*2);
}


bool BinaryHeap::isEmpty() { return data.size == 0; }
int BinaryHeap::getSize() { return data.size / 2; }  // divide by 2 to get num of (vertex, distance) pairs

void BinaryHeap::insert(int vertex, int distance){
    if (getSize() >= data.capacity / 2){
        data.resize(data.capacity * 2);
    }

    data.append(vertex);
    data.append(distance);
    assert(data.size % 2 == 0);

    int i = getSize() - 1; 
    while (i > 0 and compare(i, parent(i))){
        swap(i, parent(i));
        i = parent(i);
    }
}

DynamicArray BinaryHeap::extractRoot(){
    if (isEmpty()){
        throw std::out_of_range("Heap is empty");
    }

    DynamicArray root = DynamicArray();
    root.append(data.array[0]);
    root.append(data.array[1]);
   
    int lastIndex = getSize() - 1;
    std::cerr << "Last index of array " << lastIndex << std::endl;
    std::cerr << "last vertex: " << data.array[lastIndex * 2] << " distance: " << data.array[lastIndex*2 + 1] << std::endl;
    data.array[0] = data.array[lastIndex*2];
    data.array[1] = data.array[lastIndex*2 + 1];
    data.size -= 2;
    std::cerr << "Size of Array " << data.size << std::endl;

    heapify(0);

    return root;
}

int main() {
    BinaryHeap pq(5);
    pq.insert(1, 10);
    pq.insert(6, 1);
    pq.insert(6, 1);
    pq.insert(6, 1);
    pq.insert(2, 5);
    pq.insert(3, 7);
    pq.insert(4, 2);
    pq.insert(5, 8);

    std::cout << "Extracted elements (vertex, distance):" << std::endl;
    while (!pq.isEmpty()){
        DynamicArray el = pq.extractRoot();
        std::cout << "(" << el.get(0) << ", " << el.get(1) << ") " << std::endl;
    }
    return 0;
}


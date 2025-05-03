#include "dynamic_array.h"
#include <stdexcept>


DynamicArray::DynamicArray() : size(0), capacity(0), array(nullptr) {}

DynamicArray::DynamicArray(int size, int initialValue) : size(size) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = initialValue;
    }
}
////////////////////////////////////////////////////////////////////////////
// chat-gpt corner

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
    array = new int[size]; // Deep copy: allocate new memory
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this == &other) {
        return *this; // Prevent self-assignment
    }

    // Deep copy:
    delete_array(); // First, free existing memory

    size = other.size;
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }

    return *this;
}

// chat-gpt corner
///////////////////////////////////////////////////////////////////////////

int DynamicArray::get(int index) const{
  if (index < 0 or index >= size){
    throw std::out_of_range("Error! Index out of range.");
  }
  return array[index]; 
}

void DynamicArray::resize(int new_capacity){
  if (new_capacity < 0){
    throw std::invalid_argument("Error! Capacity can't be negative.");
  }
  int* new_array = new int[new_capacity];
  int copy_size = std::min(size, new_capacity);
  for (int i = 0; i < copy_size; i++){
      new_array[i] = array[i];
  }
  delete_array();
  array = new_array;
  capacity = new_capacity;
  size = copy_size;
}

void DynamicArray::append(int value){
  if (size >= capacity){
    int new_capacity;
    if (capacity != 0){
      new_capacity = capacity*2;
    } else {
      new_capacity = 1;
    }
    int* new_array = new int[new_capacity];
    for (int i = 0; i < size; i++){
      new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    capacity = new_capacity;
  }
  array[size] = value;
  size++;
}

void DynamicArray::delete_array(){
  if (array == nullptr){
    return;
  }
  delete[] array; 
  array = nullptr;
  capacity = 0;
  size = 0;
}

DynamicArray::~DynamicArray(){
  delete_array();
}


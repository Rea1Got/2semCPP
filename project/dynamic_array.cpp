#include "dynamic_array.h"
//#include <iostream>
#include <stdexcept>


DynamicArray::DynamicArray() : size(0), capacity(INIT_CAPACITY), array(new int[INIT_CAPACITY]) {}

DynamicArray::DynamicArray(int initialSize, int value) : size(0), capacity(initialSize), array(new int[initialSize]) {
  for (int i = 0; i < initialSize; i++){
    append(value);
  }
}

int DynamicArray::get(int index){
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
    delete_array();
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

//int main(){
//  DynamicArray myArray;
//  std::cout << myArray.capacity << std::endl;
// for(int i = 0; i < 10; i++){
//    myArray.append(i);
//    std::cout << myArray.get(i);
// }
//  myArray.delete_array();
//  return 0;
//}

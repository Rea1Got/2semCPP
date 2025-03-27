#include "dynamic_array.h"
//#include <iostream>
#include <stdexcept>


DynamicArray::DynamicArray(int value){
  for (int i = 0; i < capacity; i++){
    array[i] = value;
  }
}

int DynamicArray::get(int index){
  if (index < 0 or index >= capacity){
    throw std::out_of_range("Error! Index out of range.");
  }
  return array[index]; 
}

void DynamicArray::resize(int new_capacity){
  if (new_capacity < 0){
    throw std::invalid_argument("Error! Capacity can't be negative.");
  }
  int* new_array = new int[new_capacity];
  for (int i = 0; i < size; i++){
    new_array[i] = array[i];
  }
  delete_array();
  array = new_array;
  capacity = new_capacity;
  if (size > capacity){
    size = capacity;
  }
}

void DynamicArray::append(int value){
  if (size >= capacity){
    int new_capacity = capacity*2;
    int* new_array = new int[new_capacity];
    for (int i = 0; i < size; i++){
      new_array[i] = array[i];
    }
    delete_array();
    array = new_array;
    capacity = capacity*2;
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

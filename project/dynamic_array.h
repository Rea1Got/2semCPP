#ifndef DYNAMIC_ARRAY_H 
#define DYNAMIC_ARRAY_H 


#define INIT_CAPACITY 32

struct DynamicArray{
  int size = 0;
  int capacity = INIT_CAPACITY;
  int* array = new int[INIT_CAPACITY];

  DynamicArray(int value = 0);
  int get(int index);
  int getSize();
  int getCapacity();
  void resize(int new_capacity);
  void append(int value);
  void delete_array();
};

#endif 


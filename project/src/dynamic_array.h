#ifndef DYNAMIC_ARRAY_H 
#define DYNAMIC_ARRAY_H 

#define INIT_CAPACITY 32

struct DynamicArray{
  int size;
  int capacity;
  int* array; 

  DynamicArray();
  DynamicArray(int initialSize, int value);
  DynamicArray(const DynamicArray& other);
  DynamicArray& operator=(const DynamicArray& other); 

  int get(int index) const;
  void resize(int new_capacity);
  void append(int value);
  void delete_array();

  ~DynamicArray();
};

#endif 


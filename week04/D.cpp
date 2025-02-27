#include <iostream>

void reshape_arr(int*& ptr, unsigned int N, unsigned int M){
  int* arr = new int[M];
  for(int i = 0; i < M; i++){
    if (i < N){
      arr[i] = ptr[i];
    } else {
      arr[i] = 0;
    }
  }
  delete[] ptr;
  ptr = arr;
}

int main() {
    unsigned int N = 1;
    unsigned int M = 1;
    int* myArray = new int[N]{1}; // Инициализация массива

    reshape_arr(myArray, N, M);

    // Печать нового массива
    for (unsigned int i = 0; i < M; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение памяти
    delete[] myArray;

    return 0;
}

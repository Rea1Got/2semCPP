#include <iostream>

void write2dArray(int**& array, int lenN, int lenM){
  for (int i = 0; i < lenN; i++){
    for (int j = 0; j < lenM; j++){
      std::cin >> array[i][j];
    }
  }
}

int searchKey(int** array, int lenN, int lenM, int key){
  int row = 0, column = lenM - 1;
  while(row < lenN and column >= 0){
    if (array[row][column] == key){
      return 1;
    } else if (array[row][column] < key){
      row++;
    } else {
      column--;
    }
  }
  return 0;
}

int main(){
  int n, m, k = 0;
  std::cin >> n >> m >> k;

  int** array = new int*[n];
  for (int i = 0; i < n; i++){
    array[i] = new int[m];
  }

  write2dArray(array, n, m);
  std::cout << searchKey(array, n, m, k) << std::endl;
  for (int i = 0; i < n; i++){
    delete[] array[i];
  }
  delete[] array;
  array = nullptr;

  return 0;
}

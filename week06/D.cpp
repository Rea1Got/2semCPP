#include <iostream>

struct PairInt {
  int first = 0;
  int second = 0;

  PairInt(int a, int b){
    first = a;
    second = b;
  }
};

int main(){
  int n1, n2 = 0;
  std::cin >> n1;
  int* array1 = new int[n1 * 2];
  for (int i = 0; i < n1 * 2; i++){
    std::cin >> array1[i];
  }
  std::cin >> n2;
  int* array2 = new int[n2 * 2];
  for (int i = 0; i < n2 * 2; i++){
    std::cin >> array2[i];
  }
  
  return 0;
}

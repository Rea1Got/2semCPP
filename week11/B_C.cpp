#include <iostream>

int* cutting(int n, int* prices, int& num_cuts){
  int* dp = new int[n+1];
  int *cuts = new int[n+1];
  for (int i = 0; i <= n; i++){
    dp[i] = 0;
    cuts[i] = 0;
  }
  for (int i = 1; i <= n; i++){
    int res = 0;
    int cut = 0;
    for (int j = 1; j <= std::min(i, 10); j++){
      if (prices[j] + dp[i - j] > res){
        res = std::max(res, prices[j] + dp[i-j]);
        cut = j;
      }
    }
    dp[i] = res;
    cuts[i] = cut;
  }

  num_cuts = 0;
  int temp_n = n;
  while (temp_n > 0) {
      num_cuts++;
      temp_n -= cuts[temp_n];
  }

  int* result = new int[num_cuts];
  int index = 0;
  while (n > 0) {
      result[index++] = cuts[n];
      n -= cuts[n];
  }

  delete[] dp;  
  delete[] cuts; 

  return result;
}

int main() {
  int n = 0;
  std::cin >> n;
  int prices[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  
  int number_cuts = 0;
  int* result = cutting(n, prices, number_cuts);
  for (int i = 0; i < number_cuts; i++){
    std::cout << result[i] << " ";
  }
  delete[] result;
  result = nullptr;
  return 0;
}

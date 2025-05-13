#include <iostream>

long long int kuznechik(int x){
  long long int dp[40];
  for (int i = 0; i < 40; i++){
    dp[i] = 0;
  }
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  
  for (int i = 4; i <= x; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }

  return dp[x];
}

int main() {
  int x = 0;
  std::cin >> x;
  std::cout << kuznechik(x);
  return 0;
}

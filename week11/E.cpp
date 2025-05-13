#include <iostream>

int func(std::string s1, std::string s2){
  int len_1 = s1.length();
  int len_2 = s2.length();
  int** dp = new int*[len_1 + 1];
  for (int i = 0; i < len_1 + 1; i++){
    dp[i] = new int[len_2 + 1];
    for (int j = 0; j < len_2 + 1; j++){
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i < len_1 + 1; i++){
    for (int j = 1; j < len_2 + 1; j++){
      if (s1[i - 1] == s2[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  int result = dp[len_1][len_2];

  for (int i = 0; i < len_1 + 1; i++){
    delete[] dp[i];
    dp[i] = nullptr;
  }
  delete[] dp;
  dp = nullptr;

  return result*100/std::min(len_1, len_2);
}

int main() {
  std::string s1;
  std::string s2;
  std::cin >> s1 >> s2;
  std::cout << func(s1, s2) << std::endl;
  return 0;
}

#include <iostream>
#include <vector>

long long int maxProfit(std::vector<int> lengths, std::vector<int> prices, int n) {
    if (n <= 0) return 0;
  
    std::vector<long long int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        long long int maxVal = -1000000000;
        for (int j = 0; j < i; ++j) {
            int prevIndex = i - j - 1;
            if (prevIndex >= 0 && j < 10) {
                maxVal = std::max(maxVal, prices[j] + dp[prevIndex]);
                if (prices[j] + dp[prevIndex] == maxVal){
                    std::cout << prices[j] << ' ';
                }
            }
        }
        dp[i] = maxVal;
    }
    return dp[n];
}

int main() {
    std::vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 0;
    std::cin >> n;
    long long int profit = maxProfit(lengths, prices, n);
    std::cout << profit << std::endl;

    return 0;
} 

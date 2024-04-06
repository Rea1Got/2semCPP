// #include <iostream>
// #include <algorithm>
// #include <cstring>

// int removeCharsFromString (std::string &str, char* charsToRemove) {
//    for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
//       str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
//       return 1;
//    }
// }

// std::string Dna (std::string &s1, std::string &s2, int cnt){
//     for (int i = 0; i < __min(s1.length(), s2.length()); i++){
//         for (int j = 0; j < i; j++){
//            if (s1[j] == s2[j]){
//                 removeCharsFromString(s1, *s1[j]);
//                 removeCharsFromString(s2, *s2[j]);
//                 return Dna(s1, s2, cnt++);
//             }
//         }
//     }
//     return cnt;
// } 

// int main() {
//     std::string s1;
//     std::string s2;
//     std::cin >> s1 >> s2;
//     std::cout << Dna(s1, s2)*100/__min(s1, s2);
//     return 0;
// }

#include <iostream>
#include <vector>

int findLCS(const std::string& str1, const std::string& str2) {
    int n = str1.size();
    int m = str2.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int calculateSimilarity(const std::string& str1, const std::string& str2) {
    int lcsLength = findLCS(str1, str2);
    double similarity = static_cast<double>(lcsLength)/std::max(str1.size(), str2.size()) * 100;
    similarity = int(similarity);
    return similarity;
}

int main() {
    std::string dna1, dna2;
    std::cin >> dna1 >> dna2;
    double similarity = calculateSimilarity(dna1, dna2);
    std::cout << similarity << std::endl;

    return 0;
}

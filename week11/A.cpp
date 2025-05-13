#include <iostream>

long long int fib_square(int n){
    if (n < 2) {
        return 1; 
    }
    if (n == 2) {
        return 4; 
    }

    long long int g_minus_1 = 4;
    long long int g_minus_2 = 1; 
    long long int g_minus_3 = 1;  

    long long int result = 0;
    for (int i = 3; i <= n; i++){
        result = 2 * g_minus_1 + 2 * g_minus_2 - g_minus_3;
        g_minus_3 = g_minus_2;
        g_minus_2 = g_minus_1;
        g_minus_1 = result;
    }
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fib_square(n) << std::endl;
    return 0;
}



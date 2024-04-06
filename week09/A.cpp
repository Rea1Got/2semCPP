#include <iostream>

using namespace std;

int64_t table[41] = {0};

int64_t fib(int n){
    if (table[n] != 0){
        return table[n];
    }

    int64_t result = 0;
    result = 2*fib(n - 1) + 2*fib(n - 2) - fib(n - 3);
    table[n] = result;
    return result;
}

int main(){
    int n = 0;
    cin >> n;
    table[0] = 1;
    table[1] = 1;
    table[2] = 4;
    table[3] = 9;
    cout << fib(n);
    return 0;
}
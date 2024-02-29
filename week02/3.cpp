#include <iostream>

using namespace std;

unsigned long long collatz_conjecture_count(unsigned long long n, unsigned long long sum = 0){
    if (n == 1){
        return sum;
    }
    if (n % 2 == 0){
        return collatz_conjecture_count(n/2, ++sum);
    } else {
        return collatz_conjecture_count(3*n + 1, ++sum);
    }
}

int main(){
    unsigned long long int n = 0;
    cin >> n;
    cout << collatz_conjecture_count(n);
    return 0;
}
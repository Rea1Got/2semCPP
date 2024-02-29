#include <iostream>

using namespace std;

long long int pow(long long int curr, long long int base, long long int power){
    if (power > 1){
        return pow(curr*base, base, power-1);
    } else if (power == 0){
        return 1;
    } else {
        return curr;
    }
}

int main(){
    long long int n = 0, m = 0;
    cin >> n >> m;
    cout << pow(n, n, m);
    return 0;
}
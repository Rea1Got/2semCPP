#include <iostream>

using namespace std;

unsigned long long int redux (unsigned long long int n){
    unsigned long long int res = 0;
    while (n > 0){
        res += n%10;
        n /= 10;
    }
    if (res > 9){
        return redux(res);
    } else {
        return res;
    }
}

int main(){
    unsigned long long int n = 0;
    cin >> n;
    cout << redux(n);
    return 0;
}
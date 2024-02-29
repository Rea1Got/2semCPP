#include <iostream>
#include <cstddef>
#include <cstdint>

using namespace std;

void toBase(uint64_t n, uint64_t base){
    if (n < base){
        cout << n;
        return;
    }

    uint64_t res = n/base;

    if (res >= base){
        toBase(res, base);
    } else {
        cout << res;
    }
    toBase(n%base, base);
}

int main(){
    uint64_t n = 0, base = 0;
    cin >> n >> base;
    toBase(n, base);
    return 0;
}
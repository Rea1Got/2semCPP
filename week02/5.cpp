#include <iostream>
#include <cmath>

using namespace std;

bool is_square(uint64_t n) {
    return (bool)((uint64_t)(sqrt(n)) * (uint64_t)(sqrt(n)) == n);
}
 
int main() {
    uint64_t n = 0;
    cin >> n;
    cout << is_square(n);
    
    return 0;
}
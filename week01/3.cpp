#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 0;
    int res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++){
        res *= i;
    }
    cout << res;
    return 0;
}

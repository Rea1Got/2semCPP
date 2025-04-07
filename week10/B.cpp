#include <iostream>

using namespace std;

int main()
{
    long long int m, n, i = 0;
    cin >> m >> n;
    while (m) {
        for (i = n / m; i * m < n; ++i);
        m = m * i - n;
        n *= i;
        cout << i << ' ';
    }
    return 0;
}

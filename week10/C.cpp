#include <iostream>

using namespace std;

int main(){    
    int k, m = 0;
    cin >> k;
    int *prices = new int[k];;
    for (int i = 0; i < k; i++){
        cin >> prices[i];
    }
    cin >> m;

    int res = 0;
    while (m != 0)
    {
        if (m / prices[k - 1] > 0){
            res += m / prices[ k - 1];
            m = m % prices[k - 1];
        }
        k--;
    }
    cout << res;
    delete[] prices;
    prices = nullptr;
    return 0;
}

// #include <iostream>

// using namespace std;

// int main() {
//     int k = 0;
//     cin >> k;
//     int *a = new int[k];
//     for(int i = 0; i < k; ++i) {
//         cin >> a[i];
//     }
//     int c = 0,M =0;
//     cin >> M;
//     while(M != 0) {
//         c += M/a[k-1];
//         M = M % a[k-1];
//         k--;
//     }
//     cout << c;
//     delete[] a;
//     return 0;
// }

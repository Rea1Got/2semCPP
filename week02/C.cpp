#include <iostream>

using namespace std;

int main(){
    int n = 0;
    bool flag = true;

    cin >> n;
    while (n > 1){
        if (n % 2 == 0){
            n /= 2;
        } else {
            cout << "NO" << endl;
            flag = false;
            break;
        }
    }
    if (flag) {cout << "YES" << endl;}

    return 0;
}
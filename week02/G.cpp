#include <iostream>

using namespace std;

// p-1! + 1 == 0

int main(){
    int n = 0;
    bool flag = true;
    cin >> n;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            cout << "NO" << endl;
            flag = false;
            break;
        } 
    }
    if (flag) {cout << "YES" << endl;}
    return 0;
}
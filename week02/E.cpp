#include <iostream>

using namespace std;

int fibb(int n){
    if (n == 0 or n == 1){
        return 1;
    } else {
        return fibb(n - 1) + fibb (n - 2);
    }
}

int main(){
    int n = 0;
    cin >> n;
    cout << fibb(n) << endl;

    return 0;
}
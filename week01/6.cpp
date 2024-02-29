#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    bool flag = true;
    cin >> a;

    int len = a.length();
    for (int i = 0; i < len/2; i++){
        if (a[i] != a[len-i-1]){
            flag = false;
        }
    }
    if (flag){
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;    
}
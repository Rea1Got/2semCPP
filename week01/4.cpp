#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a >> b;
    
    while (b){
        c = a % b;
        a = b;
        b = c;
    }

    cout << a << endl;
    return 0;
}

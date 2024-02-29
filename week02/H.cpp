#include <iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while (b){
        c = a % b;
        a = b;
        b = c;
    }   
    return a; 
}

void solve(int a, int b, int c, int& x, int& y){
    if (c % gcd(a, b) == 0){
        
    } else {
        cout << 0 << endl;
    }
}

int main(){
    int a = 0, b = 0, c = 0, x = 0, y = 0;
    cin >> a >> b >> c;
    solve(a, b, c, &x, &y);
    return 0;
}
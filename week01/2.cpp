#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    double epsilone = 0.00001;
    double discr;
    cin >> a >> b >> c;
    discr = sqrt(b*b - 4*a*c);
    if (a != 0){
        if (discr > epsilone){
            cout << ((-1)*b - discr)/(2*a) << ' ' << ((-1)*b + discr)/(2*a) << endl;
        } else if ((discr >= (-1)*epsilone) && (discr <= epsilone)){
            cout << (-1)*b/(2*a);
        } else {
            cout << endl;
        }
    } else if (b != 0) {
        if (c != 0){    
            cout << (-1)*double(c)/double(b);
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << endl;
    }
    return 0;
}

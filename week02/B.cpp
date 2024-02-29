#include <iostream>

using namespace std;

int main(){
    int a = 1, res = 0;
    while (a != 0){
        cin >> a;
        if ((a % 2 == 0) and (a != 0)){
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
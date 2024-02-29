#include <iostream>

using namespace std;

long long int fact(long long int result, int duration){
    if (duration == 0 or duration == 1){
        return result;
    }
    return fact(result*duration, duration - 1);
}

int main(){
    long long int n = 0;
    cin >> n;
    cout << fact(1, n) << endl;
    return 0;
}
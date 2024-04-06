#include <iostream>
#include <cs
using namespace std;

uint64_t numTraject(int n){
    uint64_t traject[60];
    traject[0] = 1;
    traject[1] = 1;
    traject[2] = 2;
    for (int i = 3; i <= n; i++){
        traject[i] = traject[i-1] + traject[i-2] + traject[i-3];
    }
    return traject[n];
}

int main(){
    int n = 0;
    cin >> n;
    cout << numTraject(n);
    return 0;
}
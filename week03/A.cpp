#include <iostream>

#define N 10

using namespace std;

void readArray(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

int main(){
    int arr[N] = {0};
    readArray(arr);
    return 0;
}
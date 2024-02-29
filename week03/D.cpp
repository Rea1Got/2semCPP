#include <iostream>

#define N 10

using namespace std;

void readArray(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void printArray(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void shiftArrayRight(int (&arr)[N]){
    int prevNum = arr[N-1];
    for (int i = N-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = prevNum;
}

int main(){
    int arr[N] = {0};
    readArray(arr);
    shiftArrayRight(arr);
    printArray(arr);
    return 0;
}
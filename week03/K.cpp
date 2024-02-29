#include <iostream>

#define N 3

using namespace std;

void readArray(int (&arr)[N * N]){
    for (int i = 0; i < N*N; i++){
        cin >> arr[i];
    }
}

void printArray(int (&arr)[N * N]){
    for (int i = 0; i < N*N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int trace(int (&arr)[N * N]){
    int res = 0;
    for (int i = 0; i < N; i++){
        res += arr[i*N + i];
    }
    return res;
}
int main(){
    int arr[N * N] = {0};
    readArray(arr);
    cout << trace(arr);
    return 0;
}
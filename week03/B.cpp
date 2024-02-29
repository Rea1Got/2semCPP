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


int main(){
    int arr[N] = {0};
    readArray(arr);
    printArray(arr);
    return 0;
}
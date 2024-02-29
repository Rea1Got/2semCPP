#include <iostream>

#define N 5

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

void reverseArray(int (&arr)[N]){
    for (int i = 0; i < N/2; i++){
        swap(arr[i], arr[N-i-1]);
    }
}


int main(){
    int arr[N] = {0};
    readArray(arr);
    reverseArray(arr);
    printArray(arr);
    return 0;
}
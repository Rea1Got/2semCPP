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

void moveNegativeToEnd(int (&arr)[N]){
    int count = 0;
    for (int i = N-1; i >= 0; i--){
        if (arr[i] < 0){
            count++;
            for (int j = i; j < N-count; j++){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[N] = {0};
    readArray(arr);
    moveNegativeToEnd(arr);
    printArray(arr);
    return 0;
}
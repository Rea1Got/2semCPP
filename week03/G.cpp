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

int findLastZero(int (&arr)[N]){
    int left = 0, right = N-1, pos = N/2;
    while (left <= right){
        if (arr[pos] == 1){
            right = pos - 1;
        } else {
            left = pos + 1;   
        }
        pos = (left + right) / 2;
    }
    return pos;
}

int main(){
    int arr[N] = {0};
    readArray(arr);
    cout << findLastZero(arr);
//  printArray(arr);
    return 0;
}
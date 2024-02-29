#include <iostream>

#define N 10

using namespace std;

void readArray(int (&arr)[N]){
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void printArray(int (&arr)[2*N]){
    for (int i = 0; i < 2*N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]){
    for (int i = 0; i < N; i++){
        res[i] = lhs[i];
        res[N+i] = rhs[i];
    }
}

int main(){
    int arr1[N] = {0}, arr2[N] = {0}, arr3[2 * N] = {0};
    readArray(arr1);
    readArray(arr2);
    mergeArrays(arr1, arr2, arr3);
    printArray(arr3);
    return 0;
}
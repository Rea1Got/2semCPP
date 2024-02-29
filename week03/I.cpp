#include <iostream>

#define N 3
#define M 4

using namespace std;

void readArray(int (&arr)[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){    
            cin >> arr[i][j];
        }
    }
}

void printArray(int (&arr)[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void printTransposed(int (&arr)[N][M]){
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[N][M] = {{0}};
    readArray(arr);
    printTransposed(arr);
    return 0;
}
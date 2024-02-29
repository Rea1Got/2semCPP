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

void sort2d(int (&arr)[N][M]){
    int tmp[N*M] = {0};
    int count = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            tmp[count] = arr[i][j];
            count++;
        }
    }

    for (int i = 0; i < N*M; i++){
        for (int j = 0; j < N*M-1; j++){
            if (tmp[j] > tmp[j+1]){
                swap(tmp[j], tmp[j+1]);
            }
        }
    }
    
    count = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            arr[i][j] = tmp[count];
            count++;
        }
    }
}

int main(){
    int arr[N][M] = {{0}};
    readArray(arr);
    sort2d(arr);
    printArray(arr);
    return 0;
}
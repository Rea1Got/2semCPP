#include <iostream>

using namespace std;

int main(){
    long long int s, n = 0;
    cin >> s >> n;
    int* volume = new int[n];
    for (int i = 0; i < n; i++){
        cin >> volume[i];
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (volume[i] > volume[j]){swap(volume[i], volume[j]);}
        }
    }
    int res = 0, current_volume = 0;
    for(int i = 0; i < n; i++){
        if (current_volume + volume[i] > s){
            break;
        }
        res++;
        current_volume += volume[i];
    }
    cout << res << endl;
    delete[] volume;
    volume = nullptr;
    return 0;
}

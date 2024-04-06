#include <iostream>

using namespace std;

int main(){  
    int n, k, len, km, count = 0;
    bool flag = true;
    cin >> n >> k >> len;
    int *roz = new int[len];
    for (int i = 0; i < n; i++){
        cin >> roz[i];
    }
    
    for (int i = 1; i < n; i++){
        if (km >= n){
            break;
        }
        if (km + k >= roz[i-1] - roz[i]){
            km += k;
            count++;
        } else {
            flag = false;
            break;
        }
    }
    if (flag){
        cout << count;
    } else{
        cout << -1;
    }
    delete [] roz; 
    return 0;
}
#include <iostream>

using namespace std;

int main(){  
    int N, k, s = 0;
    cin >> N >> k >> s; 
    int *charges = new int[N];
    for (int i = 0; i < s; i++){
        cin >> charges[i];
    }

    bool flag = true;
    int currentPos = 0;
    int numCharges = 0;

    while (currentPos < N) {
        int nextCharge = currentPos;

        for (int i = 0; i < s; i++) {
            if (charges[i] - currentPos <= k) {
                nextCharge = charges[i];
            } else {
                break;
            }
        }

        if (nextCharge == currentPos) {
            if (currentPos + k >= N){
                break;
            } else {
                flag = false;
                break;
            }
        }

        currentPos = nextCharge;
        numCharges++;
    }

    if (flag){
        cout << numCharges;
    } else {
        cout << -1;
    }
    delete [] charges;
    return 0;
}
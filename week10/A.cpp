#include <iostream>

using namespace std;

int main(){
    int prices[6] = {98, 63, 49, 28, 7, 1};
    int count = 0;
    int change = 0;
    int m = 0;
    cin >> m;
    while (m != 0)
    {
        if (m / prices[change] > 0){
            count += m / prices[change];
            m = m % prices[change];
        }
        change++;
    }
    cout << count;
    
    return 0;
}
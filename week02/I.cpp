#include <iostream>
#include <cstdint>

using namespace std;

int res = 0;

void log2(uint64_t num, uint64_t startNum){
    if (num >= startNum*2){
        res++;
        log2(num, startNum*2);
    }
}

int main(){
    uint64_t n = 0, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num;
        log2(num, 1);
        cout << res << endl;
        res = 0;
    }
    return 0;
}
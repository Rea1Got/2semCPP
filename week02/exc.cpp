#include <iostream>

using namespace std;

int sum_ab(int a, int b)
{
    return a + b;
}

void print(int a)
{
    cout << "Your number is here, idiot: " << a << endl;
}

int main()
{
    int x = 0, y = 1;
    cin >> x >> y;
    cout << sum_ab(x, y) << endl;
    print(sum_ab(x, y));
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        scanf_s("%d,%d", &a, &b);
        cout << a + b << '\n';
    }
}
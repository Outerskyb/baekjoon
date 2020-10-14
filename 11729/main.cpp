#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int s, int d) {
    if (n == 1) {
        cout << s << ' ' << d << '\n';
        return;
    }

    hanoi(n - 1, s, 6 - s - d);
    hanoi(1, s, d);
    hanoi(n - 1, 6 - s - d,d);
}

int main()
{
    int n;
    cin >> n;
    cout << int(pow(2, n))-1 << '\n';
    hanoi(n, 1, 3);
}
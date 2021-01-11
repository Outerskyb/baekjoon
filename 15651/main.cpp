#include <iostream>

using namespace std;

int n, m;
int arr[7];
void func(int num, int p) {
    arr[p] = num;
    if (p == m - 1) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        func(i, p + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        func(i, 0);
}
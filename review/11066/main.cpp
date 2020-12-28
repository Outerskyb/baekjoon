#include <iostream>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int a[501];
int b[501][501];
int c[501][501];

int func(int y, int x) {
    if (y == x) return 0;
    if (c[y][x] != 0) return  c[y][x];
    c[y][x] = 987654321;
    for (int i = 0; i < x - y; i++) {
        c[y][x] = min(c[y][x], func(y, y + i) + b[y][y + i] + b[y + i+1][x] + func(y + i+1, x));
    }
    return c[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            b[i][i] = a[i];
        }
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                b[i][j] = b[i][j - 1] + a[j];
            }
        }

        cout << func(0, k - 1) << '\n';
    }
}
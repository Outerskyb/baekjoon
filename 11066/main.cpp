#include <iostream>
#include <cstring>

#define min(a,b) (((a)<(b)?(a):(b)))

using namespace std;

int a[501];
int b[501][501];
int d[501][501];

int func(int y, int x) {
    if (y == x) return 0;
    if (d[y][x] != 0) return d[y][x];
    int temp = 987654321;
    for (int l = 0; l < x - y; l++) {
        temp = min(temp, func(y,y + l) + b[y][y + l] + func(y + l + 1,x) + b[y + l + 1][x]);
    }
    return d[y][x] = temp;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(d, 0, sizeof d);
        int k;
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

        cout << func(0, k-1)<<'\n';
    }
}
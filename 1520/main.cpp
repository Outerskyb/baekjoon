#include <iostream>
#include <cstring>

using namespace std;

int m, n;
int dp[500][500];
int map[500][500];

int func(int y, int x) {
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    if (y > 0 && map[y - 1][x] > map[y][x])
        dp[y][x] += func(y - 1, x);
    if (x > 0 && map[y][x - 1] > map[y][x])
        dp[y][x] += func(y, x - 1);
    if (y < m - 1 && map[y + 1][x] > map[y][x])
        dp[y][x] += func(y + 1, x);
    if (x < n - 1 && map[y][x + 1] > map[y][x])
        dp[y][x] += func(y, x + 1);
    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    dp[0][0] = 1;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    cout << func(m - 1, n - 1);
}
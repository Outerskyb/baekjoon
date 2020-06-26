#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int map[300][300];
int dp[300][300];
int n, m;

int func(int y, int x) {
    if (y < 0 || x < 0) return 0;
    else if (dp[y][x] != -1) return dp[y][x];
    return dp[y][x] = max(func(y - 1, x), func(y, x - 1)) + map[y][x];
}
int main()
{
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    cout << func(n - 1, m - 1);
}
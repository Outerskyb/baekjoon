#include <iostream>
#include <cstring>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n, m;
int board[1001][1001];
long long dp[1001][1001][3];
bool visit[1001][1001];

int func(int y, int x,int d) {
    if (dp[y][x][d] != -987654321) return dp[y][x][d];
    if (y == n - 1 && x == m - 1) return dp[y][x][d] = board[y][x];
    int rslt =-987654321;
    if (y < n-1 && !visit[y + 1][x]) visit[y + 1][x] = true, rslt = max(rslt, func(y + 1, x,0) + board[y][x]), visit[y + 1][x] = false;
    if (x > 0 && !visit[y][x - 1]) visit[y][x - 1] = true,   rslt = max(rslt, func(y, x - 1,1) + board[y][x]), visit[y][x - 1] = false;
    if (x < m-1 && !visit[y][x + 1]) visit[y][x + 1] = true, rslt = max(rslt, func(y, x + 1,2) + board[y][x]), visit[y][x + 1] = false;
    return dp[y][x][d]=rslt;
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -987654321;
        }
    }
    visit[0][0] = true;
    cout << func(0, 0,0);
}
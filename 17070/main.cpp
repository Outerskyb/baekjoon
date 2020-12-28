#include <iostream>

using namespace std;

int board[16][16];
int dp[16][16][3];

int func(int y, int x, int w)
{
    if (x < 1)  return 0;
    if (y == 0 && x == 1 && w == 0) return dp[y][x][w]=1; 
    if (dp[y][x][w] != 0) return dp[y][x][w]; 
    if (w == 0) {
        if (x > 0 && !board[y][x - 1]) dp[y][x][w] += func(y, x - 1, 0);
        if (x > 0 && !board[y][x - 1]) dp[y][x][w] += func(y, x - 1, 1);
    }
    else if (w == 1) {
        if (y > 0 && (board[y][x] || board[y - 1][x] || board[y][x - 1])) return dp[y][x][w] = 0;
        if (y > 0 && x > 0 && !board[y-1][x - 1]) dp[y][x][w] += func(y - 1, x - 1, 0);
        if (y > 0 && x > 0 && !board[y-1][x - 1]) dp[y][x][w] += func(y - 1, x - 1, 1);
        if (y > 0 && x > 0 && !board[y-1][x - 1]) dp[y][x][w] += func(y - 1, x - 1, 2);
    }
    else {
        if (y > 0 && !board[y-1][x]) dp[y][x][w] += func(y - 1, x, 1);
        if (y > 0 && !board[y-1][x]) dp[y][x][w] += func(y - 1, x, 2);
    }
    return dp[y][x][w];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    dp[0][1][0] = 1;
    if (board[n-1][n-1] == 1) {
        cout << 0; return 0;
    }
    cout << func(n - 1, n - 1, 0) + func(n - 1, n - 1, 1) + func(n - 1, n - 1, 2);
}
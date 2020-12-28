#include <iostream>
#include <cinttypes>
#include <cstring>

using namespace std;

int64_t dp[100][21], board[100];

int64_t func(int p, int v)
{
    if (dp[p][v] != 0) { return dp[p][v]; }

    dp[p][v] = 0;
    if (p > 0 && v - board[p] >= 0) dp[p][v] += func(p - 1, v - board[p]);
    if (p > 0 && v + board[p] < 21) dp[p][v] += func(p - 1, v + board[p]);
  
    return dp[p][v];
}

int main()
{
    memset(dp, 0, sizeof dp);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    dp[0][board[0]] = 1;
    cout << func(n - 2, board[n - 1]);
}
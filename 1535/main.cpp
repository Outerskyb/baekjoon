#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int l[20], j[20];
int dp[21][101];

int func(int n, int h)
{
    if (dp[n][h] != -1) return dp[n][h];
    if (n == 0 || h < 1) return 0;

    return dp[n][h] = max(dp[n][h], func(n - 1, h + l[n]) + j[n]);
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> j[i];

    cout << func(n, 100);
}
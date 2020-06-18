#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][1001];

int func(int n, int r)
{
    if (dp[n][r] != -1) return dp[n][r];
    if (r == 0 || r == n) return 1;

    return dp[n][r] = (func(n - 1, r)%10007 + func(n - 1, r - 1) % 10007) % 10007;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n, r;
    cin >> n >> r;
    cout << func(n, r);
}
#include <iostream>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
    int n;
    int dp[100001];
    memset(dp, 125, sizeof dp);
    dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 2, dp[4] = 2, dp[5] = 1, dp[6] = 2, dp[7] = 1;
    cin >> n;
    for (int i = 8; i <= n; i++) {
        dp[i] = min(dp[i - 1] + 1, dp[i]);
        dp[i] = min(dp[i - 2] + 1, dp[i]);
        dp[i] = min(dp[i - 5] + 1, dp[i]);
        dp[i] = min(dp[i - 7] + 1, dp[i]);
    }
    cout << dp[n];
}
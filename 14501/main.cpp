#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
int dp[15][6];
int t[15], p[15];

int func(int n, int ok) {
    if (dp[n][ok] != -1) return dp[n][ok];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }
    if(t[0]<=n) dp[0][t[0]] = p[0];
    int ans = max(0,dp[0][t[0]]);
    for (int i = 1; i < n; i++) {
        
        int M = dp[i - 1][0];
        for (int j = 1; j < 6; j++)
            if (i - j >= 0) M = max(dp[i - j][j], M);
        dp[i][0] = M;
        ans = max(ans, dp[i][0]);
        dp[i][t[i]] = M + ((t[i] + i <= n) ? p[i] : 0);
        ans = max(ans, dp[i][t[i]]);
    }

    cout << ans;
}
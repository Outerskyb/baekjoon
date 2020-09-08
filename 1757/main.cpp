#include <iostream>
#include <cstring>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;
int dp[10001][502];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int d[10001];
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        dp[i][0] = 0;
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i+1][0] = max(dp[i+1][0],dp[i][0]);
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] == -1)
                continue;
            if (i + j <= n)
            {
                dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
            if (j < m)
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + d[i]);
        }
    }
    cout << ans;
}
#include <iostream>
#include <cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            dp[i][j] = temp - '0';
            ans |= dp[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j]) {
                dp[i][j] += min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans;
}
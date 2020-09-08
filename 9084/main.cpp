#include <iostream>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int coin[20];
        int dp[20][10001] = {0};
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
            dp[i][coin[i]] = 1;
        }
        int m;
        cin >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i)
                    dp[i][j] += dp[i - 1][j];
                if (j - coin[i] >= 0) {
                    dp[i][j] += dp[i][j - coin[i]];
                    if (i)
                        dp[i][j] += dp[i - 1][j - coin[i]];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i][m]);

        cout << ans << '\n';
    }
}
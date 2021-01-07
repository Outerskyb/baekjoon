#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int coin[20];
        int dp[20][10001] = { 0 };
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
            dp[i][coin[i]] = 1;
        }
        int m;
        cin >> m;

        sort(coin, coin + n);
        dp[0][coin[0]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 10000; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j >= coin[i]) dp[i][j] += dp[i][j - coin[i]];
            }
        }

        cout << dp[n - 1][m] << '\n';
    }
}
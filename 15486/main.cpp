#include <iostream>
#include <cstring>
#include <deque>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
deque<deque<int>> dp(51);

vector<int> t, p;

int func(int n, int ok) {
    if (dp[n][ok] != -1) return dp[n][ok];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 51; i++)
        dp.push_back(deque<int>(50));

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t.push_back(a); p.push_back(b);
    }

    if (t[0] <= n) dp[0][t[0]] = p[0];

    int ans = max(0, dp[0][t[0]]);
    for (int cnt = 1; cnt < n; cnt++) {
        int i = cnt;
        if (cnt > 50) {
            i = 50;
            dp.pop_front();
            dp.push_back(deque<int>(50));
        }

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
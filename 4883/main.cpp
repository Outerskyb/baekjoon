#include <iostream>

#define min(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 1;
    while (1) {
        int dp[100000][3];
        int map[100000][3];
        int n;
        cin >> n;
        if(n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> map[i][0] >> map[i][1] >> map[i][2];
        }
        dp[1][0] = map[0][1] + map[1][0];
        dp[1][1] = min(min(dp[1][0] + map[1][1], map[0][1] + map[1][1]),map[0][1]+map[0][2]+map[1][1]);
        dp[1][2] = min(min(dp[1][1], map[0][1]), map[0][1] + map[0][2]) + map[1][2];

        for (int i = 2; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + map[i][0];
            dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), min(dp[i - 1][2], dp[i][0])) + map[i][1];
            dp[i][2] = min(min(dp[i-1][1],dp[i-1][2]),dp[i][1])+map[i][2];
        }

        cout << cnt++ << ". " << dp[n-1][1]<<'\n';
    }
}
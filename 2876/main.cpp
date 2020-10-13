#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dp[100000][5]={{0,}};
    int n;
    cin >> n;
    int M = 0, M_idx = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--,b--;
        int temp = max(a,b);
        a = min(a,b);
        b = temp;
        if(i==0) dp[i][a] = 1,dp[i][b] = 1;
        else dp[i][a] = dp[i - 1][a] + 1, dp[i][b] = dp[i - 1][b] + 1;
        if (dp[i][a] > M)
            M = dp[i][a], M_idx = a;
        if (dp[i][b] > M)
            M = dp[i][b], M_idx = b;
    }
    cout << M <<' ' << M_idx+1;
}
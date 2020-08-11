#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cables[501];
    memset(cables,-1,sizeof cables);
    int dp[500] = {0};

    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        int a, b;
        cin >> a >> b;
        cables[a] = b;
    }

    int M = 0;
    for (int i = 0; i < 501; i++) {
        if(cables[i] == -1) continue;
        for (int j = 0; j < i; j++) {
            if (cables[j] < cables[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        M = max(M,dp[i]);
    }
    memset(dp,0,sizeof dp);
/*
    for (int i = 0; i < 501; i++) {
        if(cables[i] == -1) continue;
        for (int j = 0; j < i; j++) {
            if (cables[j] > cables[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        M = max(M,dp[i]);
    }
  */
    cout << C-M;
}
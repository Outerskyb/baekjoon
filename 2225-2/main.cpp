#include "bits/stdc++.h"

using namespace std;

int dp[201][201];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i <= n; i++) {
            for (int l = 0; l <= i; l++)
                dp[i][j] = (dp[i][j] % 1000000000 + dp[i - l][j - 1] % 1000000000) % 1000000000;
        }
    }
    cout << dp[n][k];
}

/*
1 2
0 1  1 0 n+1
2 2
0 2  1 1  2 0 n+1 
20 2
0 20  1 19  2 18 ..... 20 0 n+1

1 3
0 0 1  0 1 0  1 0 0 
2 3
0 1 1  1 0 1  1 1 0  2 0 0  0 2 0  0 0 2
*/
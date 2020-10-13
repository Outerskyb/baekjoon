#include "bits/stdc++.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int wall[500][500];
int dp[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> wall[i][j];
            dp[i][j] = wall[i][j];
        }
    }

    for (int i = 1; i < h; i++) {
        dp[i][0] += max(dp[i - 1][0], dp[i - 1][1]);
        for (int j = 1; j < w - 1; j++) {
            dp[i][j] += max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]);
        }
        dp[i][w - 1] += max(dp[i - 1][w - 2], dp[i - 1][w - 1]);
    }

    int M = 0;
    for (int i = 0; i < w; i++) {
        M = max(dp[h - 1][i], M);
    }
    cout << M;
}
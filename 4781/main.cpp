#include <cstring>
#include <iostream>
#include <vector>
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int dp[5000][10000];

int main() {
    while (1) {
        int n;
        float m;
        scanf("%d %f", &n, &m);
        m *= 100;
        if (n == 0) break;
        memset(dp, 0, sizeof dp);

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            int cal;
            float price;
            scanf("%d %f", &cal, &price);
            vec.push_back({cal, price * 100});
        }
        int M = 0;
        for (int i = 0; i < n; i++) {
            for (int j = m; j >= 0; j--) {
                if (i)
                    dp[i][j] = dp[i - 1][j];
                if (j + vec[i].second <= m)
                    dp[i][j] = max(dp[i][j], dp[i][j + vec[i].second] + vec[i].first);
                M = max(M, dp[i][j]);
            }
        }
        cout << M << '\n';
    }
}
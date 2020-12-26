#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int board[1000][1000];
int dp[1000][1000] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
          
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j != 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j - 1]);
                }
            }
            if (j != 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
                
            dp[i][j] += board[i][j];
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}
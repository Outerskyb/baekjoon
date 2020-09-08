#include <cstring>
#include <iostream>

using namespace std;

int map[100][100];
int dp[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N - 1 && j == N - 1) continue;
            if (i + map[i][j] < N) dp[i + map[i][j]][j] += dp[i][j];
            if (j + map[i][j] < N) dp[i][map[i][j] + j] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1];
    return 0;
}
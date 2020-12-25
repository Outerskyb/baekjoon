#include <iostream>
#include <vector>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int board[501][501];
bool visited[501][501];
int dp[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            dp[i][j] = 1;
            vec.push_back({ board[i][j],{i,j} });
        }
    }
    sort(vec.begin(), vec.end());
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,-1,0,1 };
    int ans = 0;
    for (const auto& el : vec) {
        int y = el.second.first, x = el.second.second;
        for (int i = 0; i < 4; i++) {
            if (y+dy[i]>=0&&y+dy[i]<n&&
                x+dx[i]>=0&&x+dx[i]<n&&board[y+dy[i]][x+dx[i]] < board[y][x])
                dp[y][x] = max(dp[y+dy[i]][x+dx[i]] + 1,dp[y][x]);
            ans = max(ans, dp[y][x]);
        }
    }
    cout << ans;
}
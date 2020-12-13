#include "bits/stdc++.h"

using namespace std;

int n, m;
bool board[1000][1000];
bool vst[1000][1000][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct s {
    int y;
    int x;
    int l;
    bool b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            board[i][j] = temp == '1';
        }
    queue<s> q;
    q.push({0, 0, 1, true});

    while (!q.empty()) {
        auto y = q.front().y;
        auto x = q.front().x;
        auto l = q.front().l;
        auto b = q.front().b;
        q.pop();
        if (y == n - 1 && x == m - 1) {
            cout << l;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < m && !board[y + dy[i]][x + dx[i]] && !vst[y + dy[i]][x + dx[i]][b]) {
                q.push({y + dy[i], x + dx[i], l + 1, b});
                vst[y + dy[i]][x + dx[i]][b] = true;
            }
            if (b && y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < m && board[y + dy[i]][x + dx[i]] && !vst[y + dy[i]][x + dx[i]][b]) {
                q.push({y + dy[i], x + dx[i], l + 1, false});
                vst[y + dy[i]][x + dx[i]][0] = true;
            }
        }
    }
    cout << -1;
}
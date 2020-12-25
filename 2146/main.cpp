#include "bits/stdc++.h"

using namespace std;

int dx[] = {-1, 0};
int dy[] = {0, -1};

int xd[] = {-1, 0, 1, 0};
int yd[] = {0, 1, 0, -1};

int board[100][100];
pair<int, int> p[100][100];
bool visited[100][100];

struct s {
    int y;
    int x;
    int l;
    int c;
};

pair<int, int> find(int y, int x) {
    if (p[y][x].first == -1) return {y, x};
    return p[y][x] = find(p[y][x].first, p[y][x].second);
}

void merge(int y1, int x1, int y2, int x2) {
    auto o = find(y1, x1);
    auto t = find(y2, x2);
    if (o == t) return;
    p[y2][x2] = o;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(p, -1, sizeof p);
    int color = 1;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp) {
                for (int k = 0; k < 2; k++)
                    if (i + dy[k] >= 0 && i + dy[k] < N && j + dx[k] >= 0 && j + dx[k] < N && board[i + dy[k]][j + dx[k]])
                        merge(i, j, i + dy[k], j + dx[k]), board[i][j] = board[i + dy[k]][j + dx[k]];

                if (!board[i][j])
                    board[i][j] = color++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j];
                while (!q.empty()) {
                    auto y = q.front().first;
                    auto x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                        if (y + yd[k] >= 0 && y + yd[k] < N && x + xd[k] >= 0 && x + xd[k] < N && !visited[y + yd[k]][x + xd[k]] && board[y + yd[k]][x + xd[k]]) {
                            board[y + yd[k]][x + xd[k]] = board[i][j];
                            q.push({y + yd[k], x + xd[k]});
                            visited[y + yd[k]][x + xd[k]] = true;
                        }
                }
            }
        }
    }

    int ans = 987654321;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                memset(visited, 0, sizeof visited);
                queue<s> q;
                q.push({i, j, 0, board[i][j]});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto y = q.front().y;
                    auto x = q.front().x;
                    auto l = q.front().l;
                    auto c = q.front().c;
                    q.pop();
                    if (board[y][x] != 0 && board[y][x] != c) {
                        ans = min(ans, l - 1);
                        break;
                    }
                    for (int k = 0; k < 4; k++) {
                        if (y + yd[k] >= 0 && y + yd[k] < N && x + xd[k] >= 0 && x + xd[k] < N && !visited[y + yd[k]][x + xd[k]] && (board[y + yd[k]][x + xd[k]] != c)) {
                            q.push({y + yd[k], x + xd[k], l + 1, c});
                            visited[y + yd[k]][x + xd[k]] = true;
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}
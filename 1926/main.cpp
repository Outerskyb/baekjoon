#include <iostream>
#include <queue>

using namespace std;

int map[500][500];
bool visit[500][500];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    int area = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            area = 0;
            if (map[i][j] && !visit[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i][j] = true;
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    area++;
                    int y = curr.first;
                    int x = curr.second;

                    if (y < n - 1 && map[y + 1][x] && !visit[y + 1][x]) {
                        q.push({y + 1, x});
                        visit[y + 1][x] = true;
                    }
                    if (x < m - 1 && map[y][x + 1] && !visit[y][x + 1]) {
                        q.push({y, x + 1});
                        visit[y][x + 1] = true;
                    }
                    if (y > 0 && map[y - 1][x] && !visit[y - 1][x]) {
                        q.push({y - 1, x});
                        visit[y - 1][x] = true;
                    }
                    if (x > 0 && map[y][x - 1] && !visit[y][x - 1]) {
                        q.push({y, x - 1});
                        if (y < n - 1 && map[y + 1][x] && !visit[y + 1][x]) {
                            q.push({y + 1, x});
                            visit[y + 1][x] = true;
                        }
                        visit[y][x - 1] = true;
                    }
                }
                max = max > area ? max : area;
                cnt++;
            }
        }
    }
    cout << cnt <<'\n'<<max;
}
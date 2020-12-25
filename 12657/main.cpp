#include "bits/stdc++.h"

using namespace std;

int board[10][10];
pair<int, int> region[10][10];

pair<int, int> find(int y, int x) {
    if (region[y][x].first < 0) return {y, x};
    region[y][x] = find(region[y][x].first, region[y][x].second);
    return region[y][x];
}

void merge(pair<int, int> p1, pair<int, int> p2) {
    p1 = find(p1.first, p1.second);
    p2 = find(p2.first, p2.second);
    if (p1 == p2) return;
    region[p2.first][p2.second] = p1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int w, h, M = -1;
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                //bfs 귀찮아
            }
        }
    }
}

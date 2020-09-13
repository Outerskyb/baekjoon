#include <iostream>
#include <queue>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;
using pii = pair<int, int>;
pii dir8[] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
pii dir4[] = { {0,1},{-1,0},{0,-1},{1,0}};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char map[500][500];
    bool visit[500][500];
    memset(visit, 0, sizeof visit);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    bool adj = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'W') {
                queue<pii> q;
                q.push({ i,j });
                while (!q.empty()) {
                    auto y = q.front().first;
                    auto x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if (y + dir4[k].first < r && y + dir4[k].first >= 0
                            && x + dir4[k].second < c && x + dir4[k].second >= 0
                            && map[y + dir4[k].first][x + dir4[k].second] == 'S')
                        {
                            adj = true;
                            goto out;
                        }
                    }
                }
            }
        }
    }
out:;
    if (!adj) {
        cout << 1 << '\n';
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == '.') map[i][j] = 'D';
                cout << map[i][j];
            }
            cout << '\n';
        }
    }
    else {
        cout << 0;
    }
}

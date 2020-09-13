#include <iostream>
#include <queue>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

struct s {
    int y;
    int x;
    int l;
};

using namespace std;
using pii = pair<int, int>;
pii dir8[] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
pii dir4[] = { {0,1},{-1,0},{0,-1},{1,0} };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char map[182][182];

    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    int rslt[182][182];
    memset(rslt, 64, sizeof rslt);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == '1') {
                bool visit[182][182];
                memset(visit, 0, sizeof visit);
                queue<s> q;
                q.push({ i,j,0 });
                while (!q.empty()) {
                    auto y = q.front().y;
                    auto x = q.front().x;
                    auto l = q.front().l;
                    rslt[y][x] = min(l, rslt[y][x]);
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if (y + dir4[k].first < r && y + dir4[k].first >= 0
                            && x + dir4[k].second < c && x + dir4[k].second >= 0
                            && map[y + dir4[k].first][x + dir4[k].second] == '0'
                            && !visit[y + dir4[k].first][x + dir4[k].second])
                        {
                            visit[y + dir4[k].first][x + dir4[k].second] = true;
                            q.push({ y + dir4[k].first,x + dir4[k].second,l +1 });
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (rslt[i][j] == 1077952576) rslt[i][j] = 0;
            cout << rslt[i][j];
        }
        cout << '\n';
    }
}
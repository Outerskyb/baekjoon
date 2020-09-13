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
pii dirk[] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };
pii dir4[] = { {0,1},{-1,0},{0,-1},{1,0} };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    r = c = 8;
    int map[8][8];
    bool visit[8][8];
    memset(visit, 0, sizeof visit);
    int sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    sy--, sx--, ey--, ex--;
    queue<s> q;
    q.push({ sy,sx,0 });
    while (!q.empty()) {
        auto y = q.front().y;
        auto x = q.front().x;
        auto l = q.front().l;
        q.pop();
        if (y == ey && x == ex) {
            cout << l;
            return 0;
        }
        for (int k = 0; k < 8; k++) {
            if (y + dirk[k].first < r && y + dirk[k].first >= 0
                && x + dirk[k].second < c && x + dirk[k].second >= 0
                && !visit[y + dirk[k].first][x + dirk[k].second])
            {
                visit[y + dirk[k].first][x + dirk[k].second] = true;
                q.push({ y + dirk[k].first,x + dirk[k].second,l + 1 });
            }
        }
    }
}
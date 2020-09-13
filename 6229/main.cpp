#include <iostream>
#include <queue>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;
using pii = pair<int, int>;
pii dir8[] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
pii dir4[] = { {0,1},{-1,0},{0,-1},{1,0} };
struct s {
    int y;
    int x;
    int l;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int map[30][30];
    bool visit[30][30];
    memset(visit, 0, sizeof visit);
    int r, c, m1, m2;
    cin >> r >> c >> m1 >> m2;
    pii dir8[] = { {m1,m2},{m1,-m2},{-m1,m2},{-m1,-m2},{m2,m1},{-m2,m1},{m2,-m1},{-m2,-m1} };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 3 && !visit[i][j]) {
                queue<s> q;
                q.push({ i,j,0 });
                visit[i][j] = true;
                while (!q.empty()) {
                    auto y = q.front().y;
                    auto x = q.front().x;
                    auto l = q.front().l;
                    q.pop();

                    for (int k = 0; k < 8; k++) {
                        if (y + dir8[k].first < r && y + dir8[k].first >= 0
                            && x + dir8[k].second < c && x + dir8[k].second >= 0
                            && map[y + dir8[k].first][x + dir8[k].second] == 1
                            && !visit[y + dir8[k].first][x + dir8[k].second])
                        {
                            visit[y + dir8[k].first][x + dir8[k].second] = true;
                            q.push({ y + dir8[k].first,x + dir8[k].second,l+1 });
                            cnt++;
                        }
                        if (y + dir8[k].first < r && y + dir8[k].first >= 0
                            && x + dir8[k].second < c && x + dir8[k].second >= 0
                            && map[y + dir8[k].first][x + dir8[k].second] == 4) {
                            cout << l+1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
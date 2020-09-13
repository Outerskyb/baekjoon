#include <iostream>
#include <queue>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

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

    char map[10][10];
    bool visit[10][10];
    memset(visit, 0, sizeof visit);
    int r, c;
    r = c = 10;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'L' && !visit[i][j]) {
                cnt++;
                queue<s> q;
                q.push({ i,j,0 });
                while (!q.empty()) {
                    auto y = q.front().y;
                    auto x = q.front().x;
                    auto l = q.front().l;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if (y + dir4[k].first < r && y + dir4[k].first >= 0
                            && x + dir4[k].second < c && x + dir4[k].second >= 0
                            && map[y + dir4[k].first][x + dir4[k].second] == '.' 
                            && !visit[y + dir4[k].first][x + dir4[k].second])
                        {
                            visit[y + dir4[k].first][x + dir4[k].second] = true;
                            q.push({ y + dir4[k].first,x + dir4[k].second,l+1 });
                        }
                        if (y + dir4[k].first < r && y + dir4[k].first >= 0
                            && x + dir4[k].second < c && x + dir4[k].second >= 0
                            && map[y + dir4[k].first][x + dir4[k].second] == 'B') {
                            cout << l;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
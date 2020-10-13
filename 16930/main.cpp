#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[1000][1000];
bool visit[1000][1000];
bool is_posible[1000][1000][4];
pair<int, int> dir4[] = { {0,1},{-1,0},{0,-1},{1,0} };

struct s {
    int y;
    int x;
    int l;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            map[i][j] = (temp == '.');
        }
    }
    memset(is_posible, 1, 1000 * 1000 * 4);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    queue<s> q;
    q.push({ x1,y1,0 });
    visit[x1][y1] = true;
    int level = 0;
    bool occupied[1000][1000] = { 0, };
    while (!q.empty())
    {
        auto y = q.front().y;
        auto x = q.front().x;
        auto l = q.front().l;

        if (l != level) {
            level = l;
            memset(occupied, 0, 1000 * 1000);
        }
        
        q.pop();

        if (y == x2 && x == y2) {
            cout << l;
            return 0;
        }

        //bool stucked[4] = { 0 };
        for (int j = 0; j < 4; j++){
            if (!is_posible[y][x][j]) continue;
            for (int i = 1; i <= k; i++) {
                if (//!stucked[j] &&
                    y + dir4[j].first * i < n && y + dir4[j].first * i >= 0
                    && x + dir4[j].second * i <m && x + dir4[j].second * i >= 0
                    && map[y + dir4[j].first * i][x + dir4[j].second * i] == 0) {
                    //stucked[j] = true;
                    for (int it = 0; it <= i; it++) {
                        is_posible[y + dir4[j].first * it][x + dir4[j].second * it][j] = false;
                    }
                    break;
                }
                if (y + dir4[j].first * i < n && y + dir4[j].first * i >= 0
                    && x + dir4[j].second * i < m && x + dir4[j].second * i >= 0
                    && visit[y + dir4[j].first * i][x + dir4[j].second * i]
                    && !occupied[y + dir4[j].first * i][x + dir4[j].second * i]) {
                    for (int it = 0; it <= i; it++) {
                        is_posible[y + dir4[j].first * it][x + dir4[j].second * it][j] = false;
                    }
                    break;
                }
                if (//!stucked[j] &&
                    y + dir4[j].first * i < n && y + dir4[j].first * i >= 0
                    && x + dir4[j].second * i < m && x + dir4[j].second * i >= 0
                    && map[y + dir4[j].first * i][x + dir4[j].second * i] == 1
                    && !visit[y + dir4[j].first * i][x + dir4[j].second * i])
                {
                    visit[y + dir4[j].first * i][x + dir4[j].second * i] = true;
                    is_posible[y + dir4[j].first * i][x + dir4[j].second * i][j + 2 % 4] = false;
                    q.push({ y + dir4[j].first * i,x + dir4[j].second * i,l + 1 });
                    occupied[y + dir4[j].first * i][x + dir4[j].second * i] = true;
                    if (y + dir4[j].first * i == x2 && x + dir4[j].second * i == y2) {
                        cout << l+1;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1;
}

/*
3 3 2
..#
.#.
...
2 3 1 1

3
*/
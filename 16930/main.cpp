#include <iostream>
#include <queue>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int map[1000][1000];
bool visit[1000][1000];
bool is_posible[1000][1000][4];
int dp[1000][1000];
const int inf = 1077952576;
pair<int, int> dir4[] = { {0,1},{-1,0},{0,-1},{1,0} };

struct s {
    int y;
    int x;
};

int main()
{
    memset(dp,64,sizeof dp);
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
    q.push({ x1,y1 });
    visit[x1][y1] = true;
    dp[x1][y1] = 0;
    while (!q.empty())
    {
        auto y = q.front().y;
        auto x = q.front().x;
       // cout << y << ' ' << x << ' ' << l<<'\n';
        q.pop();

        if (y == x2 && x == y2) {
            cout << dp[y][x]+1;
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
                if(y + dir4[j].first * i < n && y + dir4[j].first * i >= 0
                    && x + dir4[j].second * i <m && x + dir4[j].second * i >= 0
                    &&dp[y][x]+1 > dp[y + dir4[j].first * i][x + dir4[j].second * i]){
                        break;
                    }
                if (//!stucked[j] &&
                    y + dir4[j].first * i < n && y + dir4[j].first * i >= 0
                    && x + dir4[j].second * i < m && x + dir4[j].second * i >= 0
                    && map[y + dir4[j].first * i][x + dir4[j].second * i] == 1
                    && !visit[y + dir4[j].first * i][x + dir4[j].second * i])
                {
                    visit[y + dir4[j].first * i][x + dir4[j].second * i] = true;
                    dp[y + dir4[j].first * i][x + dir4[j].second * i] = min(dp[y + dir4[j].first * i][x + dir4[j].second * i],dp[y][x]+1);
                    q.push({ y + dir4[j].first * i,x + dir4[j].second * i });
                    if (y + dir4[j].first * i == x2 && x + dir4[j].second * i == y2) {
                        cout << dp[y][x] +1;
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
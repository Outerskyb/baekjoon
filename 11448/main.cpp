#include <iostream>
#include <queue>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;
using pii = pair<int, int>;
pii dir8[] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        char map[100][100];
        bool visit[100][100];
        memset(visit, 0, sizeof visit);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 'w') {
                    queue<pii> q;
                    q.push({ i,j });
                    int cnt = 0;
                    while (!q.empty()) {
                        auto y = q.front().first;
                        auto x = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++) {
                            if (y + dir8[k].first < n  && y + dir8[k].first>=0
                                && x + dir8[k].second < n  && x + dir8[k].second>=0
                                && map[y + dir8[k].first][x + dir8[k].second] == '-'
                                && !visit[y + dir8[k].first][x + dir8[k].second])
                            {
                                cnt++;
                                visit[y + dir8[k].first][x + dir8[k].second] = true;
                                q.push({ y + dir8[k].first,x + dir8[k].second });
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << '\n';

    }

}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int map[100][100] = { 0 };
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            map[i][j] = ((i==j)?0:123456789);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        map[b][a] = map[a][b] = 1;
    }

    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    bool is_checked[100] = { 0, };
    vector<vector<int>> cc;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        if (!is_checked[i]) {
            vector<int> c;
            c.push_back(i);
            queue<int> que;
            que.push(i);
            while (!que.empty()) {
                int curr = que.front();
                que.pop();
                for (int j = 0; j < n; j++) {
                    if (j == i || is_checked[j]) continue;
                    if (map[curr][j] != 0 && map[curr][j] != 123456789) {
                        que.push(j);
                        c.push_back(j);
                        is_checked[j] = true;
                    }
                }
            }
            int min = 223456789;
            int min_idx = 0;
            for (auto& j : c) {
                int max = 0;
                for (auto& k : c) {
                    if (j == k) continue;
                    max = (max > map[j][k]) ? max : map[j][k];
                }
                if (min > max) {
                    min = max;
                    min_idx = j;
                }
            }
            answer.push_back(min_idx+1);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size()<<'\n';
    for (auto el : answer) cout << el << '\n';
}
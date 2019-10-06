#include <iostream>
#include <vector>
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
        map[a][b] = 1;
    }

    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    vector<pair<int, int>> vec(n, { 0,0 });

    for (int i = 0; i < n; i++) {
        vec[i].second = i;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            vec[i].first += map[i][j];
        }
    }

    sort(vec.begin(), vec.end());
    for (auto& p : vec) cout << p.second << '\n';
}
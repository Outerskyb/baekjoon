#include <iostream>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> map(n);
    for (int i = 0; i < n; i++) map[i] = vector<int>(n, 10000);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        map[a][b] = map[b][a] = 1;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
            }
        }
    }
    
    map[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j == i) continue;
            map[i][0] += map[i][j];
        }
    }

    int max=123456789, max_idx=0;
    for (int i = 0; i < n; i++) {
        if (map[i][0] < max) max = map[i][0], max_idx = i;
    }
    cout << max_idx + 1;

}
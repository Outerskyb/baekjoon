#include <iostream>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

pair<int, int> mat[500];
pair<int, int> s[500][500];
int d[500][500];

int func(int y, int x) {
    if (y == x) return 0;
    if (d[y][x] != 0) return d[y][x];
    d[y][x] = 987654321;
    for (int i = 0; i < x - y; i++) {
        d[y][x] = min(func(y,y + i) + s[y][y + i].first*s[y][y+i].second*s[y+i+1][x].second+func(y+i+1,x), d[y][x]);
    }
    return d[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mat[i].first >> mat[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s[i][j] = { mat[i].first, mat[j].second };
        }
    }
    cout << func(0, n - 1);

}
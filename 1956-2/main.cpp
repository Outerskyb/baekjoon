#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    int map[400][400];
    for (int i = 0; i < 400 * 400; i++)
        * ((int*)map + i) = 123456789;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a - 1][b - 1] = c;
    }
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                map[i][j] = ((map[i][j] < map[i][k] + map[k][j]) ? map[i][j] : (map[i][k] + map[k][j]));
            }
        }
    }
    int max = 223456789;
    for (int i = 0; i < v; i++) {
        if (map[i][i] < max) max = map[i][i];
    }
    cout << ((max == 123456789) ? -1 : max);
}
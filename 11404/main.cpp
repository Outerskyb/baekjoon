#include <iostream>
#include <cstring>
using namespace std;

unsigned int map[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int m;
	cin >> n >> m;
	memset(map, -1, 101 * 101 * 4);
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) map[i][j] /= 2, map[i][j]--, map[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = (map[a][b] > c) ? c : map[a][b];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout <<  ((map[i][j]== 2147483646)?0:map[i][j]) << ' ';
		}
		cout << '\n';
	}
}
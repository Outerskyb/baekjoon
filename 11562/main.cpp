#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int map[250][250];
	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		map[u][v] = 1;
		if (b) map[v][u] = 1;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = (map[i][j] < map[i][k] + map[k][j]) ? map[i][j] : map[i][k] + map[k][j];

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int s, e;
		cin >> s >> e;
		cout << 
	}

}
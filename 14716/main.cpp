#include <iostream>

using namespace std;
int M, N;
bool map[250][250];

void dfs(int y, int x)
{
	map[y][x] = false;
	if (y - 1 >= 0 && map[y - 1][x]) {
		dfs(y - 1, x);
	}
	if (y + 1 < M && map[y + 1][x]) {
		dfs(y + 1, x);
	}
	if (x - 1 >= 0 && map[y][x - 1]) {
		dfs(y, x - 1);
	}
	if (x + 1 < N && map[y][x + 1]) {
		dfs(y, x + 1);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && map[y - 1][x - 1]) {
		dfs(y - 1, x - 1);
	}
	if (y - 1 >= 0 && x + 1 < N && map[y - 1][x + 1]) {
		dfs(y - 1, x + 1);
	}
	if (y + 1 < M && x - 1 >= 0 && map[y + 1][x - 1]) {
		dfs(y + 1, x - 1);
	}
	if (y + 1 < M && x + 1 < N && map[y + 1][x + 1]) {
		dfs(y + 1, x + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j]) 
				dfs(i, j), ++cnt;
		}
	}
	cout << cnt;
}
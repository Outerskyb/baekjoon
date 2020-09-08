#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int R, C;
bool visited[26];

int map[20][20];

int M;

void dfs(int r, int c, int depth)
{
	visited[map[r][c]] = true;
	M = (M > depth) ? M : depth;
	bool temp[26];
	memcpy(temp, visited, 26);
	if (r - 1 >= 0 && !visited[map[r - 1][c]]) {
		dfs(r - 1, c, depth + 1);
	}
	memcpy(visited, temp, 26);
	if (r + 1 < R && !visited[map[r + 1][c]]) {
		dfs(r + 1, c, depth + 1);
	}
	memcpy(visited, temp, 26);
	if (c - 1 >= 0 && !visited[map[r][c - 1]]) {
		dfs(r, c - 1, depth + 1);
	}
	memcpy(visited, temp, 26);
	if (c + 1 < C && !visited[map[r][c + 1]]) {
		dfs(r, c + 1, depth + 1);
	}

	memcpy(visited, temp, 26);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j]-'A';
		}
	}
	dfs(0, 0, 1);
	cout << M;
}
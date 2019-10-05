#include <iostream>
#include <cstdlib>

using namespace std;
int N, M;
bool map[101][101];
bool visited[101][101];

int cnt;

void dfs(int r, int c)
{
	visited[r][c] = true;
	cnt++;
	if (r + 1 <= N && map[r + 1][c] && !visited[r + 1][c]) {
		dfs(r + 1, c);
	}
	if (r - 1 >= 0 && map[r - 1][c] && !visited[r - 1][c]) {
		dfs(r - 1, c);
	}
	if (c + 1 <= M && map[r][c + 1] && !visited[r][c + 1]) {
		dfs(r, c + 1);
	}
	if (c - 1 >= 0 && map[r][c - 1] && !visited[r][c - 1]) {
		dfs(r, c - 1);
	}
}

int main()
{
	int K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r][c] = true;
	}
	int max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				max = (max > cnt) ? max : cnt;
			}
		}
	}
	cout << max;
}
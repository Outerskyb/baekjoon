#include <iostream>

using namespace std;

int N;
int map[101][101];
bool visit[101][101];

void dfs(int y, int x) {
	visit[y][x] = true;
	char colour = map[y][x];
	if (y + 1 < N && map[y + 1][x] == colour && !visit[y + 1][x]) {
		dfs(y + 1, x);
	}
	if (y - 1 >= 0 && map[y - 1][x] == colour && !visit[y - 1][x]) {
		dfs(y - 1, x);
	}
	if (x + 1 < N && map[y][x + 1] == colour && !visit[y][x + 1]) {
		dfs(y, x + 1);
	}
	if (x - 1 >= 0 && map[y][x - 1] == colour && !visit[y][x - 1]) {
		dfs(y, x - 1);
	}
}



int main()
{
	char temp;
	cin >> N;
	scanf("%c", &temp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &temp);
			map[i][j] = temp;
		}
		scanf("%c", &temp);
	}
	int normal_cnt = 0, blind_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0 && !visit[i][j]) {
				dfs(i, j);
				normal_cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	memset(visit, 0, 101*101);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0 && !visit[i][j]) {
				dfs(i, j);
				blind_cnt++;
			}
		}
	}
	cout << normal_cnt << ' '<<blind_cnt;
}
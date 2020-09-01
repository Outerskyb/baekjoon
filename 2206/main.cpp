#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[1001][1001];
int map2[1001][1001];
bool visit[1001][1001];

struct l {
	int y;
	int x;
	int lv;
};

int main()
{
	int  N, M;
	cin >> N >> M;

	char temp;
	scanf("%c", &temp);

	vector<pair<int, int>> vec;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			scanf("%c", &temp);
			map[i][j] = temp - '0';
		}
		char temp;
		scanf("%c", &temp);
	}

	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < M-1; j++) {
			if (map[i - 1][j] > 1 && map[i + 1][j] > 1 && map[i][j + 1] > 1 && map[i][j - 1] > 1)
				map[i][j] = 2;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(map[i][j] == 1) vec.push_back({ i,j });
		}
	}
	int min = 1001 * 1001 * 2;

	for (auto& el : vec) {
		memset(visit, 0, 1001 * 1001);
		map[el.first][el.second] = 0;

		queue<l> que;
		que.push({ 0,0,1 });
		while (!que.empty())
		{
			l curr = que.front();
			que.pop();
			if (visit[curr.y][curr.x]) continue;
			visit[curr.y][curr.x] = true;
			if (curr.y == N - 1 && curr.x == M - 1) {
				min = (min > curr.lv) ? curr.lv : min;
				break;
			}
			if (curr.y + 1 <= N - 1 && !visit[curr.y + 1][curr.x] && !map[curr.y + 1][curr.x]) {
				que.push({ curr.y + 1,curr.x,curr.lv + 1 });
			}
			if (curr.y - 1 >= 0 && !visit[curr.y - 1][curr.x] && !map[curr.y - 1][curr.x]) {
				que.push({ curr.y - 1,curr.x,curr.lv + 1 });
			}
			if (curr.x + 1 <= M - 1 && !visit[curr.y][curr.x + 1] && !map[curr.y][curr.x + 1]) {
				que.push({ curr.y ,curr.x + 1,curr.lv + 1 });
			}
			if (curr.x - 1 >= 0 && !visit[curr.y][curr.x - 1] && !map[curr.y][curr.x - 1]) {
				que.push({ curr.y ,curr.x - 1,curr.lv + 1 });
			}
		}
		map[el.first][el.second] = 1;

	}

	printf("%d", (min == 1001 * 1001 * 2) ? -1 : min);
}
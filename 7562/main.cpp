#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l;
int x, y;
int a, b;
bool visit[301][301];

struct tp {
	int y;
	int x;
	int level;
};

queue<tp> que;

void bfs()
{
	while (!que.empty()) {
		tp curr = que.front();
		que.pop();

		if (visit[curr.y][curr.x]) continue;
		visit[curr.y][curr.x] = true;
		if (curr.y == a && curr.x == b) {
			printf("%d\n", curr.level);
			return;
		}

		if (curr.y - 2 >= 0 && curr.x + 1 < l && !visit[curr.y - 2][curr.x + 1]) {
			que.push({ curr.y - 2, curr.x + 1, curr.level + 1 });
		}
		if (curr.y - 2 >= 0 && curr.x - 1 >= 0 && !visit[curr.y - 2][curr.x - 1]) {
			que.push({ curr.y - 2, curr.x - 1 , curr.level + 1 });
		}
		if (curr.y - 1 >= 0 && curr.x + 2 < l && !visit[curr.y - 1][curr.x + 2]) {
			que.push({ curr.y - 1, curr.x + 2, curr.level + 1 });
		}
		if (curr.y - 1 >= 0 && curr.x - 2 >= 0 && !visit[curr.y - 1][curr.x - 2]) {
			que.push({ curr.y - 1, curr.x - 2, curr.level + 1 });
		}
		if (curr.y + 2 < l && curr.x + 1 < l && !visit[curr.y + 2][curr.x + 1]) {
			que.push({ curr.y + 2, curr.x + 1, curr.level + 1 });
		}
		if (curr.y + 2 < l && curr.x - 1 >= 0 && !visit[curr.y + 2][curr.x - 1]) {
			que.push({ curr.y + 2, curr.x - 1 , curr.level + 1 });
		}
		if (curr.y + 1 < l && curr.x + 2 < l && !visit[curr.y + 1][curr.x + 2]) {
			que.push({ curr.y + 1, curr.x + 2, curr.level + 1 });
		}
		if (curr.y + 1 < l && curr.x - 2 >= 0 && !visit[curr.y + 1][curr.x - 2]) {
			que.push({ curr.y + 1, curr.x - 2, curr.level + 1 });
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		memset(visit, 0, 301 * 301);
		que = queue<tp>();
		scanf("%d", &l);
		scanf("%d %d %d %d", &x, &y, &a, &b);
		que.push({ x,y,0 });
		bfs();
	}
}
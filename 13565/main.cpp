#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
bool visit[1001][1001];

struct s {
	int y;
	int x;
	int l;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			map[i][j] = a - '0';
		}
	}

		for (int j = 0; j < n; j++) {
			if (!visit[0][j]&&!map[0][j]) {
				queue<s> q;
				q.push({ 0,j,0 });
				visit[0][j] = true;
				while (!q.empty()) {
					auto curr = q.front();
					q.pop();
					auto y = curr.y;
					auto x = curr.x;

					if (y == m - 1) {
						cout << "YES";
						return 0;
					}

					if (curr.y > 0 && !map[curr.y - 1][curr.x] && !visit[curr.y - 1][curr.x])
						q.push({ y - 1,x,curr.l + 1 }), visit[y - 1][x] = true;
					if (curr.y < m - 1 && !map[curr.y + 1][curr.x] && !visit[curr.y + 1][curr.x])
						q.push({ y + 1,x,curr.l + 1 }), visit[y + 1][x] = true;
					if (curr.x > 0 && !map[curr.y][curr.x - 1] && !visit[curr.y][curr.x - 1])
						q.push({ y ,x - 1,curr.l + 1 }), visit[y][x - 1] = true;
					if (curr.x < n - 1 && !map[curr.y][curr.x + 1] && !visit[curr.y][curr.x + 1])
						q.push({ y ,x + 1,curr.l + 1 }), visit[y][x + 1] = true;
				}
			}
		}

	cout << "NO";
}
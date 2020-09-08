#include <iostream>
#include <queue>

using namespace std;
struct s {
	int y;
	int x;
};

int map[100][100];
bool visit[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char temp;
			cin >> temp;
			map[i][j] = temp == '#';
		}
	}

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] && !visit[i][j]) {
				cnt++;
				queue<s> q;
				q.push({ i,j });
				while (!q.empty()) {
					auto curr = q.front();
					q.pop();
					if (curr.y < r - 1 && map[curr.y + 1][curr.x] && !visit[curr.y + 1][curr.x]) {
						visit[curr.y + 1][curr.x] = true;
						q.push({ curr.y + 1,curr.x });
					}
					if (curr.x < c - 1 && map[curr.y][curr.x + 1] && !visit[curr.y][curr.x + 1]) {
						visit[curr.y][curr.x + 1] = true;
						q.push({ curr.y,curr.x + 1 });
					}
					if (curr.y > 0 && map[curr.y - 1][curr.x] && !visit[curr.y - 1][curr.x]) {
						visit[curr.y - 1][curr.x] = true;
						q.push({ curr.y - 1,curr.x });
					}
					if (curr.x > 0 && map[curr.y][curr.x - 1] && !visit[curr.y][curr.x - 1]) {
						visit[curr.y][curr.x - 1] = true;
						q.push({ curr.y ,curr.x - 1 });
					}
				}
			}
		}
	}
	cout << cnt;
}
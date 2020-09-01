#include <iostream>
#include <queue>

using namespace std;

int map[251][251];
bool visit[251][251];

struct s {
	int y;
	int x;
	int l;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char temp;
			cin >> temp;
			map[i][j] = (temp == '.') ? 1 : (temp == '#') ? 0 : (temp == 'o') ? 2 : 3;
		}
	}
	int ans = 0;
	int S = 0, W = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != 0 && !visit[i][j]) {
				queue<s> q;
				q.push({ i,j,0 });
				visit[i][j] = true;
				int sheep = 0, wolf = 0;
				while (!q.empty()) {
					auto curr = q.front();
					q.pop();
					auto y = curr.y;
					auto x = curr.x;
					if (map[y][x] == 2) sheep++;
					else if (map[y][x] == 3) wolf++;
					if (y > 0 && map[y - 1][x] && !visit[y - 1][x])
						q.push({ y - 1,x,curr.l + 1 }), visit[y - 1][x] = true;;
					if (y < r - 1 && map[y + 1][x] && !visit[y + 1][x])
						q.push({ y + 1,x,curr.l + 1 }), visit[y + 1][x] = true;;
					if (x > 0 && map[y][x - 1] && !visit[y][x - 1])
						q.push({ y ,x - 1,curr.l + 1 }), visit[y][x - 1] = true;;
					if (x < c - 1 && map[y][x + 1] && !visit[y][x + 1])
						q.push({ y ,x + 1,curr.l + 1 }), visit[y][x + 1] = true;;
				}
				if (sheep > wolf)
					S += sheep;
				else
					W += wolf;
			}
		}
	}
	cout << S << ' ' << W;
}
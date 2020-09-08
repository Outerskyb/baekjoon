#include <iostream>
#include <queue>

using namespace std;

int main() {
	while (1) {
		char map[100][100];
		int W, H;
		cin >> W >> H;
		if (W == 0) return 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				/*				char temp;
								cin >> temp;
								map[i][j] = temp == 'T' ? 1 : temp == 'S' ? 2 : 0;*/
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 'S') {
					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						if (y < H - 1 && map[y + 1][x] == 'T') {
							map[y + 1][x] = 'S';
							q.push({ y + 1,x });
						}
						if (x < W - 1 && map[y][x + 1] == 'T') {
							map[y][x + 1] = 'S';
							q.push({ y,x + 1 });
						}
						if (y > 0 && map[y - 1][x] == 'T') {
							map[y - 1][x] = 'S';
							q.push({ y - 1,x });
						}
						if (x > 0 && map[y][x - 1] == 'T') {
							map[y][x - 1] = 'S';
							q.push({ y,x - 1 });
						}
					}
				}
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
	}
}
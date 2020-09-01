#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct s {
	int(*map)[3];
	int l;
};

bool same(int(*m1)[3]) {
	for (int i = 0; i < 9; i++) {
		if (m1[i / 3][i % 3] != 0)
			return false;
	}
	return true;
}
int main()
{
	int p;
	cin >> p;

	while (p--) {
		int map[3][3];
		for (int i = 0; i < 9; i++) {
			char a;
			cin >> a;
			map[i / 3][i % 3] = a == '*';
		}
		queue<s> q;
		q.push({ map,0 });
		while (!q.empty()) {
			auto curr = q.front();
			int cmap[3][3];
			memcpy(cmap, curr.map, 9 * 4);
			q.pop();
			if (same(cmap)) {
				cout << curr.l << '\n';
				break;
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int cmap2[3][3];
					memcpy(cmap2, cmap, 9 * 4);
					if (cmap[i][j]) {
						if (i > 0) cmap[i - 1][j] = 1 - cmap[i - 1][j];
						if (i < 2) cmap[i + 1][j] = 1 - cmap[i + 1][j];
						if (i > 0) cmap[i][j - 1] = 1 - cmap[i][j - 1];
						if (i < 2) cmap[i][j + 1] = 1 - cmap[i][j + 1];
						s n = { nullptr,0};
						memcpy(n.map, cmap, 36);
						n.l = curr.l + 1;
						q.push(n);
					}
					memcpy(cmap, cmap2, 9 * 4);
				}
			}
		}
	}
}
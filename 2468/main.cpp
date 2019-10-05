#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N;
int map[101][101];
int bmap[101][101];
bool visit[101][101];

set<int> heights;

void dfs(int y, int x) 
{
	visit[y][x] = true;
	if (y + 1 < N && bmap[y + 1][x] && !visit[y + 1][x]) {
		dfs(y + 1, x);
	}
	if (y - 1 >= 0 && bmap[y - 1][x] && !visit[y - 1][x]) {
		dfs(y - 1, x);
	}
	if (x + 1 < N && bmap[y][x + 1] && !visit[y][x + 1]) {
		dfs(y, x + 1);
	}
	if (x - 1 >= 0 && bmap[y][x - 1] && !visit[y][x - 1]) {
		dfs(y, x - 1);
	}
}


int main()
{
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			heights.insert(temp);
			map[i][j] = temp;
		}
	}
	
	int max = -1;
	
	for (auto el : heights) {
		memset(visit, 0, 101 * 101);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bmap[i][j] = (map[i][j] >= el);
			}
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bmap[i][j] && !visit[i][j]) {
					dfs(i, j);
					count++;
				}
			}
		}
		max = (max > count) ? max : count;
	}

	cout << max;
}
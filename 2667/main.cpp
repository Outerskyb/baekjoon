#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[25][25];
bool visit[25][25];

int cnt;
int N;

void dfs(int y, int x)
{
	visit[y][x] = true;
	cnt++;
	if (y + 1 < N && map[y + 1][x] && !visit[y + 1][x]) {
		dfs(y + 1, x);
	}
	if (y - 1 >= 0 && map[y - 1][x] && !visit[y - 1][x]) {
		dfs(y - 1, x);
	}
	if (x + 1 < N && map[y][x + 1] && !visit[y][x + 1]) {
		dfs(y, x + 1);
	}
	if (x - 1 >= 0 && map[y][x - 1] && !visit[y][x - 1]) {
		dfs(y, x - 1 );
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
			map[i][j] = temp - '0';
		}
		scanf("%c", &temp);
	}

	int ccnt = 0;
	vector<int> cv;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				ccnt++;
				cv.push_back(cnt);
			}
		}
	}
	sort(cv.begin(), cv.end());
	cout << ccnt<<'\n';
	for (auto el : cv) cout << el << '\n';
}
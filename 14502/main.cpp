#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int map[9][9];
bool visit[9][9];
queue<pair<int, int>> q;

int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		if (visit[curr.first][curr.second]) continue;
		visit[curr.first][curr.second] = true;
		//map[curr.first][curr.second] = 2;
		cnt++;
		if (curr.first + 1 < N && map[curr.first + 1][curr.second] != 1 && !visit[curr.first + 1][curr.second]) {
			q.push({ curr.first + 1,curr.second });
		}
		if (curr.first - 1 >= 0 && map[curr.first - 1][curr.second] != 1 && !visit[curr.first - 1][curr.second]) {
			q.push({ curr.first - 1,curr.second });
		}
		if (curr.second + 1 < M && map[curr.first][curr.second + 1] != 1 && !visit[curr.first][curr.second + 1]) {
			q.push({ curr.first,curr.second + 1 });
		}
		if (curr.second - 1 >= 0 && map[curr.first][curr.second - 1] != 1 && !visit[curr.first][curr.second - 1]) {
			q.push({ curr.first ,curr.second - 1 });
		}
	}
	return cnt;
}

void printm() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int solve()
{
	vector<pair<int, int>> vec;
	vector<pair<int, int>> vi;
	int one;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) vec.push_back({ i,j });
			if (map[i][j] == 2) vi.push_back({ i,j });
			one = N * M - vec.size() - vi.size();
		}

	int max = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (j == i) continue;
			for (int k = 0; k < vec.size(); k++) {
				if (k == i || k == j) continue;
				map[vec[i].first][vec[i].second] = 1;
				map[vec[j].first][vec[j].second] = 1;
				map[vec[k].first][vec[k].second] = 1;
				int b = 0;
				memset(visit, 0, 9 * 9);
				for (auto el : vi) {
					
					q = queue<pair<int, int>>();
					q.push({ el.first,el.second });

					 b += bfs();
					
				}
				if (max < (N * M) - b - one - 3) {
					max = (N * M) - b - one - 3;
				}
				map[vec[i].first][vec[i].second] = 0;
				map[vec[j].first][vec[j].second] = 0;
				map[vec[k].first][vec[k].second] = 0;
			}
		}
	}
	return max;
}

int main()
{

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	cout << solve();

}
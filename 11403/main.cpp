#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> adj_list(101);
bool visit[101];

int st;

void dfs(int curr) {
	if (curr == st) st = -1;
	else visit[curr] = true;
	for (auto el : adj_list[curr])
	{
		if (!visit[el]) dfs(el);
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			scanf("%d", &a);
			if (a) adj_list[i].push_back(j);
		}
	}
	for (int i = 0; i < N; i++) {
		memset(visit, 0, 101);
		st = i;
		dfs(i);
		for (int j = 0; j < N; j++) {
			printf("%d ", visit[j]);
		}
		printf("\n");
	}

}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visit[101];
vector<vector<int>> adj_list(101);

struct lv {
	int node;
	int level;
};
int n;
int a, b;
int m;
queue <lv> que;

void bfs()
{
	while (!que.empty()) {
		lv curr = que.front();
		if (curr.node == b) {
			printf("%d", curr.level); return;
		}
		que.pop();
		if (visit[curr.node]) continue;
		visit[curr.node] = true;
		for (auto el : adj_list[curr.node]) 
			if(!visit[el])
				que.push({ el,curr.level + 1});
	}
	printf("-1");
}

int main()
{
	
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	que.push({ a,0 });
	bfs();
}
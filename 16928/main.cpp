#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct s {
	int pos;
	int dep;
};
bool visit[101];
int main()
{
	int n;
	int m;
	cin >> n >> m;

	vector<pair<int,int>> vec;
	for (int i = 0; i < n+m; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}

	queue<s> q;
	q.push({ 1,0 });
	
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		visit[curr.pos] = true;
		for (auto el : vec)
			if (curr.pos == el.first)
				curr.pos = el.second;
		visit[curr.pos] = true;
		if (curr.pos == 100) {
			cout << curr.dep; return 0;
		}

		if (curr.pos + 6 <= 100 && !visit[curr.pos + 6]) q.push({ curr.pos + 6, curr.dep + 1 });
		if (curr.pos + 5 <= 100 && !visit[curr.pos + 5]) q.push({ curr.pos + 5, curr.dep + 1 });
		if (curr.pos + 4 <= 100 && !visit[curr.pos + 4]) q.push({ curr.pos + 4, curr.dep + 1 });
		if (curr.pos + 3 <= 100 && !visit[curr.pos + 3]) q.push({ curr.pos + 3, curr.dep + 1 });
		if (curr.pos + 2 <= 100 && !visit[curr.pos + 2]) q.push({ curr.pos + 2, curr.dep + 1 });
		if (curr.pos + 1 <= 100 && !visit[curr.pos + 1]) q.push({ curr.pos + 1, curr.dep + 1 });

	}

}
#include <iostream>
#include <map>
#include <queue>

using namespace std;

bool visit[300001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int S, E;
	cin >> S >> E;
	multimap<int, int> mm;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		mm.insert({ x, y });
		mm.insert({ y, x });
	}

	queue<pair<int, int>> q;
	q.push({ S,0 });
	visit[S] = true;
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		if (curr.first == E) {
			cout << curr.second;
			return  0;
		}
		if (curr.first > 1 && !visit[curr.first - 1])
			q.push({ curr.first - 1,curr.second + 1 }), visit[curr.first - 1] = true;
		if (curr.first < N && !visit[curr.first + 1])
			q.push({ curr.first + 1,curr.second + 1 }), visit[curr.first + 1] = true;

		auto it = mm.lower_bound(curr.first);
		auto e = mm.upper_bound(curr.first);
		for (; it != e; ++it)
			if (!visit[(*it).second])
				q.push({ (*it).second,curr.second + 1 }), visit[(*it).second] = true;
	}

}
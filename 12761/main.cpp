#include <iostream>
#include <queue>

using namespace std;

bool visit[100001];

struct s {
	int pos;
	int l;
};

int main() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	queue<s> q;
	q.push({ n, 0 });
	visit[n] = true;
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		if (curr.pos == m) {
			cout << curr.l;
			return 0;
		}
		if (curr.pos - 1 > 0 && !visit[curr.pos - 1])
			q.push({ curr.pos - 1,curr.l + 1 }), visit[curr.pos - 1] = true;
		if (curr.pos + 1 <= 100000 && !visit[curr.pos + 1])
			q.push({ curr.pos + 1,curr.l + 1 }), visit[curr.pos + 1] = true;
		if (curr.pos - a > 0 && !visit[curr.pos - a])
			q.push({ curr.pos - a,curr.l + 1 }), visit[curr.pos - a] = true;
		if (curr.pos - b > 0 && !visit[curr.pos - b])
			q.push({ curr.pos - b,curr.l + 1 }), visit[curr.pos - b] = true;
		if (curr.pos + a <= 100000 && !visit[curr.pos + a])
			q.push({ curr.pos + a,curr.l + 1 }), visit[curr.pos + a] = true;
		if (curr.pos + b <= 100000 && !visit[curr.pos + b])
			q.push({ curr.pos + b,curr.l + 1 }), visit[curr.pos + b] = true;
		if (curr.pos * a <= 100000 && !visit[curr.pos * a])
			q.push({ curr.pos * a,curr.l + 1 }), visit[curr.pos * a] = true;
		if (curr.pos * b <= 100000 && !visit[curr.pos * b])
			q.push({ curr.pos * b,curr.l + 1 }), visit[curr.pos * b] = true;
	}
}
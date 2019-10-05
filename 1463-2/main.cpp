#include <iostream>
#include <queue>

using namespace std;

struct l {
	int num;
	int lv;
};

int main()
{
	int X;
	bool visit[1000001] = { 0, };
	cin >> X;
	queue<l> q;
	q.push({ X,0 });
	while (!q.empty()) {
		l c = q.front();
		q.pop();
		if (visit[c.num]) continue;
		if (c.num == 1) { cout << c.lv; return 0; }
		visit[c.num] = true;

		if (c.num % 3 == 0 && !visit[c.num / 3]) {
			q.push({ c.num / 3, c.lv + 1 });
		}
		if (c.num % 2 == 0 && !visit[c.num / 2]) {
			q.push({ c.num / 2, c.lv + 1 });
		}
		if ( !visit[c.num - 1]) {
			q.push({ c.num - 1, c.lv + 1 });
		}
	}
}
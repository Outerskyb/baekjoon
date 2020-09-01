#include <iostream>
#include <queue>
#include <cinttypes>

using namespace std;

struct st {
	int64_t num;
	int depth;
};

int main()
{
	int a, b;
	cin >> a >> b;

	queue<st> que;
	que.push({ a,1 });

	while (!que.empty())
	{
		auto curr = que.front();
		que.pop();

		if (curr.num == b) {
			cout << curr.depth;
			return 0;
		}
		if (curr.num * 2 <= b)
			que.push({ curr.num * 2,curr.depth + 1 });
		if (curr.num * 10 + 1 <= b)
			que.push({ curr.num * 10 + 1,curr.depth + 1 });
	}
	cout << -1;
}
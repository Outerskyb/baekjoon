#include <iostream>
#include <queue>

using namespace std;

bool visit[100001];

struct p {
	int po;
	int dep;
};

int main()
{
	int N; int K;
	cin >> N >> K;

	queue<p> que;
	que.push({ N,0 });

	while (!que.empty()) {
		p curr = que.front(); 
		que.pop();
		if (visit[curr.po]) continue;
		if (curr.po == K) {
			printf("%d", curr.dep);
			return 0;
		}
		visit[curr.po] = true;
		if (curr.po + 1 <= 100000 && !visit[curr.po + 1]) {
			que.push({ curr.po + 1,curr.dep + 1 });
		}
		if (curr.po - 1 >= 0 && !visit[curr.po - 1]) {
			que.push({ curr.po - 1,curr.dep + 1 });
		}
		if (curr.po * 2 <= 100000 && !visit[curr.po * 2]) {
			que.push({ curr.po * 2,curr.dep + 1 });
		}
	}
}
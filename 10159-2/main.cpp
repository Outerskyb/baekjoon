#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int N;
	int M;
	cin >> N >> M;
	int bmap[101][101];
	int smap[101][101];
	memset(bmap, 0, 101 * 101 * 4);
	memset(smap, 0, 101 * 101 * 4);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		smap[b][a] = bmap[a][b] = 1;
	}

	for (int k = 1; k <= N; k++) {
		int cnt = 0;
		bool visit[101] = { 0, };
		queue<int> que;
		que.push(k);
		while (!que.empty()) {
			for (int i = 1; i <= N; i++) {
				if (bmap[que.front()][i]&&!visit[i]) visit[i] = true, que.push(i), cnt++;
			}
			que.pop();
		}
		que.push(k);
		while (!que.empty()) {
			for (int i = 1; i <= N; i++) {
				if (smap[que.front()][i] && !visit[i]) visit[i] = true, que.push(i), cnt++;
			}
			que.pop();
		}
		cout << N-1-cnt<<'\n';
	}
}
#include <iostream>
#include <queue>

using namespace std;

int map[100001];
bool visit[100001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int s;
	cin >> s;
	queue<int> q;
	q.push(s-1);
	int ans = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		++ans;
		if (curr - map[curr] >= 0 && !visit[curr - map[curr]]) 
			q.push(curr - map[curr]), visit[curr - map[curr]] = true;
		if (curr + map[curr] <= n-1 && !visit[curr + map[curr]])
			q.push(curr + map[curr]), visit[curr + map[curr]] = true;

	}
	cout << ans;
}
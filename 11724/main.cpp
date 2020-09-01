#include <iostream>
#include <vector>

using namespace std;
int cnt;
bool visited[1001];
vector<vector<int>> vec;

void dfs(int n) {
	visited[n] = true;
	for (auto node : vec[n]) {
		if (!visited[node])
			dfs(node);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;	
	cin >> n >> m;
	vec = vector<vector<int>>();
	for (int i = 0; i < n; i++) vec.push_back(vector<int>());
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		--t1, --t2;
		vec[t1].push_back(t2);
		vec[t2].push_back(t1);
	}

	for (int i = 0; i < n; i++) if(!visited[i]) ++cnt,dfs(i);
	cout << cnt;
	return 0;
}
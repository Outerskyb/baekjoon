#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int Max;
int N, M;
vector<int> list;
vector<int> max_list;
bool visit[1001];
int map[1001][1001];

void dfs(int e,int length) 
{
	list.push_back(e);
	if(length!=0) visit[e] = true;
	bool temp[1000];
	memcpy(temp, visit, 1000);
	if (e == 1&&length !=0) {
		if (Max < length) {
			Max = length;
			max_list = list;
		}
		goto out;
	}
	for (int i = 0; i <= N; i++) {
		if (map[e][i] != 0 && !visit[i]) {
			memcpy(visit, temp, 1000);
			dfs(i,length+map[e][i]);		
		}
	}
	out:
	visit[e] = false;
	list.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}

	dfs(1,0);
	cout << Max<<'\n';
	for (auto& el : max_list) {
		cout << el << ' ';
	}
}
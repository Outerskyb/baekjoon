#include <iostream>
#include <vector>

using namespace std;
vector<int> vec;
int cnt;
bool visited[100000], finished[100000];

void dfs(int curr) {
	visited[curr] = true;
	int next = vec[curr];
	if (visited[next]) {
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = vec[temp]) cnt++;
			cnt++; 
		}
	}
	else dfs(next);
	finished[curr] = true;
}


int main() 
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		scanf("%d", &n);
		vec = vector<int>();
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			vec.push_back(temp-1);
		}
		memset(visited, 0, 100000);
		memset(finished, 0, 100000);
		cnt = 0;
		for (int i = 0; i < n; i++)
			if (!visited[i]) dfs(i);
		printf("%d\n", n - cnt);
		
	}
}
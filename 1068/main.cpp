#include <iostream>
#include <cstring>

using namespace std;

int N;
int tr[50];
bool ch[50];
void dfs(int node) {
	tr[node] = -2,ch[node] =false;
	for (int i = 0; i < N; i++) {
		if (tr[i] == node) dfs(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int ri = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		tr[i] = temp;
		if (temp == -1) ri = i;
	}
	int er;
	cin >> er;
	memset(ch, 1, 50);
	dfs(er);

	
	for (int i = 0; i < N; i++) {
		if(tr[i]>=0) ch[tr[i]] = false;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if(ch[i]) cnt++;
	}
	cout << cnt;
}

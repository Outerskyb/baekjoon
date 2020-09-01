#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	int map[500][500];
	for (int i = 0; i < 500 * 500; i++) *((int*)map + i) = 123456789;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		map[a][b] = 1;
	}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = (map[i][j] > map[i][k] + map[k][j]) ? map[i][k] + map[k][j] : map[i][j];
	
	vector<int>vec(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (map[i][j] != 123456789) vec[i]++,vec[j]++;
		}
		
	}
	
	int cnt = 0;
	for (auto& el : vec) if (el == N - 1)cnt++;
	cout << cnt;
}
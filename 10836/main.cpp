#include <iostream>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	vector<int> sum(M * 2 - 1, 1);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j < a + b; j++) {
			sum[j] += 1;
		}
		for (int j = a + b; j < a + b + c; j++) {
			sum[j] += 2;
		}
	}
	vector<vector<int>> vec(M);
	for (int i = 0; i < M; i++) {
		vec[i] = vector<int>(M);
	}
	for (int i = 0; i < M; i++) {
		vec[M - i - 1][0] = sum[i];
	}
	for (int i = 0; i < M; i++) {
		vec[0][i] = sum[i + M - 1];
	}

	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			vec[i][j] = max(max(vec[i - 1][j], vec[i][j - 1]), vec[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << vec[i][j]<<' ';
		}
		cout << '\n';
	}
}
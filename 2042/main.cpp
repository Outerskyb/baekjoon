#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> vec;

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L)return 0;
	if (L <= nodeL && nodeR <= R) return vec[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

void update(int i, int val) {
	i += N;
	vec[i] = val;
	while (i > 1) {
		i /= 2;
		vec[i] = vec[i * 2] * vec[i * 2 + 1];
	}
}
void construct() {
	for (int i = N-1 ; i > 0; --i)
		vec[i] = vec[i * 2] + vec[i * 2 + 1];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vec = vector<int>(2 * N);
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp, vec[i+N]=temp;
	}
	construct();
	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << sum(b, c,1,0,N-1)<<'\n';
		}
	}
}
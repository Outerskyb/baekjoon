#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];

	sort(vec.rbegin(), vec.rend());

	int cnt = 0;
	for (auto& el : vec) {
		if (K >= el) {
			cnt += (K / el);
			K -= el * (K / el);
		}
	}

	cout << cnt;
}
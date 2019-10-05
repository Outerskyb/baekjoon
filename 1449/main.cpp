#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	int cnt = 1;
	int r = vec[0] + L-1;
	for (int i = 0; i < N; i++) {
		if (vec[i] <= r) continue;
		else {
			r = vec[i] + L - 1;
			cnt++;
		}
	}
	cout << cnt;
}
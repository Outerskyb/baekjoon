#include <iostream>
#include <cinttypes>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec(n);
	uint64_t sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		sum += vec[i];
		if (max < vec[i]) max = vec[i];
	}
	int m;
	cin >> m;
	if (sum <= m) { cout << max; return 0; }
	uint64_t l = 0;
	uint64_t h = 1'000'000'001;
	uint64_t mid = (l + h) / 2;

	while (l + 1 < h) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += (vec[i] > mid) ? mid : vec[i];
		}
		if (sum > m) {
			h = mid;
			mid = (h + l) / 2;
		}
		else {
			l = mid;
			mid = (h + l) / 2;
		}
	}
	cout << l;
}
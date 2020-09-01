#include <iostream>
#include <vector>
#include <cinttypes>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; int m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int l = 0;
	int h = 1'000'000'000;
	int mid = (l + h) / 2;
	while (l + 1 < h) {
		uint64_t sum = 0;

		for (int i = 0; i < n; i++) {
			sum += (mid > vec[i]) ? 0 : vec[i] - mid;
		}

		if (sum < m) {
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
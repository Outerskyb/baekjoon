#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, n;
	cin >> k >> n;

	vector<int> vec(k);
	for (int i = 0; i < k; i++) {
		cin >> vec[i];
	}
	uint64_t l = 0;
	uint64_t h = 100000000000;
	while (l + 1 < h) {
		uint64_t  mid = (h + l) / 2;

		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += vec[i] / mid;
		}
		
		if (cnt < n) {
			h = mid;
		}
		else {
			l = mid;
		}
	}
	cout << l;
}
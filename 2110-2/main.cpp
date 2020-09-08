#include <iostream>
#include <cinttypes>
#include <vector> 
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	uint64_t l = 0;
	uint64_t h = 1000000006;
	sort(vec.begin(), vec.end());
	while (l + 1 < h) {
		uint64_t mid = (h + l) / 2;
		uint64_t left = vec[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (vec[i] - left >= mid) {
				left = vec[i];
				cnt++;
			}
		}
		if (cnt < c) h = mid;
		else l = mid;
	}
	cout << l;
}

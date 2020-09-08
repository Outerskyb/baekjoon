#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	uint64_t l=0;
	uint64_t h=100000;

	vector<uint64_t> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	uint64_t mid;
	while (l + 1 < h) {
		mid = (h + l) / 2;
		
		int cnt = 0;
		uint64_t sum = 0;
		for (int i = 0; i < n; i++) {
			if (vec[i] > mid) {
				cnt = m + 2;
				break;
			}
			if (sum + vec[i] > mid) {
				sum = vec[i];
				cnt++;
			}
			else {
				sum += vec[i];
			}
		}

		if (cnt < m) {
			h = mid;
		}
		else {
			l = mid;
		}
	}

	cout << h;
}
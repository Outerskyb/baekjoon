#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<uint64_t> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	uint64_t l = 0; 
	uint64_t h = 10000000001;
	
	while (l + 1 < h) {
		uint64_t mid = (l + h) / 2;

		int cnt = 0;
		uint64_t sum = 0;
		for (int i = 0; i < n; i++) {
			if (vec[i] > mid) {
				cnt = m + 2;
				break;
			}
			if (sum + vec[i] > mid) {
				cnt++;
				sum = vec[i];
			}
			else {
				sum += vec[i];
			}
		}
		
		if (cnt < m) {
			h = mid;
			mid = (h + l) / 2;
		}
		else {
			l = mid;
			mid = (h + l) / 2;
		}
	}

	cout << h;
}
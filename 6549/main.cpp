#include <iostream>
#include <algorithm>
#include <cinttypes>
#include <vector>

using namespace std;

int N;
vector<int64_t> vec;

int64_t histogram(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return vec[s];

	int mid = (s + e) / 2;
	int64_t rv = max(histogram(s, mid), histogram(mid, e));

	int64_t w = 1, h = vec[mid], l = mid, r = mid;
	while (r - l + 1 < e - s) {
		int p = l > s ? min(h, vec[l - 1]) : -1;
		int q = r < e - 1 ? min(h, vec[r + 1]) : -1;

		if (p >= q) {
			l--;
			h = p;
		}
		else {
			h = q;
			r++;
		}
		rv = max(rv, ++w * h);
	}
	return rv;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N;
		if (N == 0) break;
		vec = vector<int64_t>(N);

		for (int i = 0; i < N; i++) {
			cin >> vec[i];
		}

		cout << histogram(0, N)<<'\n';
	}

}
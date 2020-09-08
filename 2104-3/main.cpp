#include <iostream>
#include <vector>
#include <cinttypes>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int N;
vector<int64_t> A;

int64_t dnq(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return A[s] * A[s];

	int mid = (s + e) / 2;
	int64_t ret = max(dnq(s, mid), dnq(mid, e));

	int64_t mini = A[mid], sum = A[mid]; int l = mid, r = mid;

	while (r - l + 1 < e - s) {
		int64_t p = l > s ?  A[l - 1] : -1;
		int64_t q = r < e-1 ? A[r + 1] : -1;
		if (p >= q) {
			mini = min(mini,A[l-1]);
			sum += A[l - 1];
			l--;
		}
		else {
			mini = min(mini,A[r+1]);
			sum += A[r + 1];
			r++;
		}
		// ÃÖ´ñ°ª °»½Å
		ret = max(ret, mini * sum);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	A = vector<int64_t>(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << dnq(0, N);
}
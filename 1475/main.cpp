#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt[10] = { 0 };
	if (N == 0) { cout << 1; return 0; }
	while (N > 0) {
		cnt[N % 10]++;
		N /= 10;
	}
	cnt[6] = (cnt[6] + cnt[9]) / 2 + (cnt[6] + cnt[9]) % 2;
	cnt[9] = 0;
	sort(cnt, cnt + 10);
	cout << cnt[9];
}
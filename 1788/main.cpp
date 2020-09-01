#include <iostream>
#include <cmath>
#include <cinttypes>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n < 0 && (n * -1) % 2 == 0) cout << -1 << '\n';
	else if (n == 0) cout << 0 << '\n';
	else cout << 1<<'\n';

	int64_t pprev = 0, prev = 1;
	int64_t now;
	n = abs(n);
	for (int i = 2; i <= n; i++) {
		now = (pprev % 1000000000 + prev % 1000000000) % 1000000000;
		pprev = prev;
		prev = now;
	}

	if (n < 2 && n >= 0) cout << n;
	else cout << now;

}
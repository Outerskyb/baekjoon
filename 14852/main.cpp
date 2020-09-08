#include <iostream>
#include <cinttypes>

using namespace std;

int main()
{
	int n;
	cin >> n;
	uint64_t pprev = 2;
	uint64_t prev = 7;
	uint64_t now = 7;
	if (n == 1) { cout << 2; return 0; }
	if (n == 2) { cout << 7; return 0; }
	for (int i = 3; i <= n; i++) {
		now = ((pprev * 4) % 1000000007 + (prev * 2) % 1000000007) % 1000000007;
		pprev = prev;
		prev = now;
	}
	cout << now;
}
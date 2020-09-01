#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	uint64_t dp[36] = { 1,1 };
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i / 2; j++)
			dp[i + 1] += dp[j] * dp[i - j] * (1 + (j != i-j));
	cout << dp[n];
}
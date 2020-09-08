#include <iostream>
#include <cinttypes>

using namespace std;

uint64_t dp[101][101];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		dp[i][0] = dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[n][m];
}
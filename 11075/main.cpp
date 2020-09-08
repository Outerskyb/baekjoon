#include <iostream>

using namespace std;

int dp[1001][10];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k]%10007;
				dp[i][j] % 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) sum += dp[n][i]%10007,sum%=10007;
	cout << sum;
}
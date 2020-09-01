#include <iostream>

using namespace std;

int main()
{
	int dp[1001] = { 0,1,0,1,1,1,1,0 };
	int n;
	cin >> n;
	for (int i = 8; i <= n; i++) {
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
			dp[i] = 1;
		else dp[i] = 0;
	}
	cout << ((dp[n])?"SK":"CY");
}
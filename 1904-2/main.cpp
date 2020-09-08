#include <iostream>
#include <cstring>
#include <cinttypes>

using namespace std;

int n;

int64_t dp[1000001];

int64_t func(int n) {
	if (dp[n] != -1) return dp[n];
	if (n == 1) return 1;
	if (n == 2) return 2;

	return dp[n] = (func(n - 1)% 15746 + func(n - 2)% 15746)%15746;
}

int main() 
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	cout << func(n);
}
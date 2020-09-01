#include <iostream>
#include <cstring>
#include <cinttypes>

using namespace std;

int n;

uint64_t dp[91][2];

uint64_t func(int n,int bin) 
{
	if (dp[n][bin] != -1) return dp[n][bin];
	if (n == 1 && bin == 1) return 1;
	if (n == 1 && bin == 0) return 0;

	if (bin == 0) dp[n][bin] = func(n - 1, 0) + func(n - 1, 1);
	if (bin == 1) dp[n][bin] = func(n - 1, 0);

	return dp[n][bin];
}

int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	cout << func(n,0)+func(n,1);
}
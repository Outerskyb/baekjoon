#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dp[1001][2];

int f(int n, int r)
{
	if (n <= 1) return r;
	if (dp[n][r] != -1) return dp[n][r];

	int& ret = dp[n][r];

	if (r == 0)
	{
		ret = (f(n - 2, 0) % 10007 + f(n - 2, 1) % 10007) % 10007;
	}
	else {
		ret = (f(n - 1, 0) % 10007 + f(n - 1, 1) % 10007) % 10007;
	}

	return dp[n][r] = ret;
}

int main()
{
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;
	//for(n = 1 ;n<10;n++)
	cout << (f(n, 0) % 10007 + f(n, 1) % 10007) % 10007;

}
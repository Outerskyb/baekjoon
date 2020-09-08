#include <iostream>
#include <cstring>
#include <cmath>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int squares[225];
int dp[100000];


int main()
{
	int n;
	cin >> n;
	memset(dp, 64, sizeof dp);
	for (int i = 1; i < 225; i++) {
		squares[i] = i * i;
		dp[squares[i]] = 1;
	}

	dp[0] = 0, dp[1] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 225; j++) {
			dp[i + squares[j]] = min(dp[i] + 1, dp[i + squares[j]]);
		}
	}

	cout << dp[n];

}
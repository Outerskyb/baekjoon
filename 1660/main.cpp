#include <iostream>
#include <cstring>
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
	int n;
	cin >> n;
	int b[130] = { 0, };
	for (int i = 1; i < 130; i++) {
		b[i] = b[i - 1] + i * (i + 1) / 2;
	}
	
	int dp[300001] ;
	memset(dp, 125, sizeof dp);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j < 130; j++) {
			if (i < b[j]) break;
			dp[i] = min(dp[i], dp[i - b[j]] + 1);
		}
	}
	cout << dp[n];

}
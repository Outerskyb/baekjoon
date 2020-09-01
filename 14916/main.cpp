#include <iostream>
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
	int dp[100001] = {50001 ,50001,1,50001,2,1,3,2,4,3,2,4,3,5 };
	int n;
	cin >> n;
	for (int i = 9; i <= n; i++) {
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	}
	cout << ((dp[n]==50001)?-1:dp[n]);
}
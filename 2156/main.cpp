#include <iostream>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[10001][2];

int main()
{
	int n;
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	dp[0][0] = 0; dp[0][1] = vec[0];
	dp[1][0] = dp[0][1],dp[1][1] = dp[0][1]+vec[1];
	dp[2][0] = dp[1][1], dp[2][1] = max(dp[1][0] + vec[2], vec[1] + vec[2]);
	
	for (int i = 3; i < n; i++) {
		dp[i][1] = max(dp[i - 2][0] + vec[i - 1], dp[i - 1][0] )+vec[i];
		dp[i][0] = max(max(dp[i - 3][0] + vec[i - 2] + vec[i - 1],dp[i-1][1]),max( dp[i-2][0],dp[i-1][0]));
	}
	cout << max(dp[n-1][1], dp[n-1][0]);
}
#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[301][301];

int main()
{
	int a, b, c, n;
	cin >> a >> b >> c >> n;

	dp[0][n] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 0; j--) {
			if (a <= j)
				dp[i][j - a] = max(dp[i][j - a], dp[i - 1][j]);
			if (b <= j)
				dp[i][j - b] = max(dp[i][j - b], dp[i - 1][j]);
			if (c <= j)
				dp[i][j - c] = max(dp[i][j - c], dp[i - 1][j]);
		}
	}
	for(int i = 0 ; i <= n ;i++)
		if (dp[i][0]) {
			cout << 1;
			return 0;
		}
	cout << 0;
}
#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int dif[100000][2][2];
	int dp[100000][2];
	int c;
	cin >> c;
	while (c--) {
		memset(dif, 0, sizeof dif);
		memset(dp, 0, sizeof dp);
		int n, l1, l2, s1, s2;
		cin >> n >> l1 >> l2 >> s1 >> s2;

		dp[0][0] = l1, dp[0][1] = l2;
		for (int i = 0; i < n - 1; i++) {
			cin >> dif[i][0][0];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> dif[i][1][0];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> dif[i][0][1];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> dif[i][1][1];
		}

		for (int i = 1; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][0] + dif[i - 1][1][0], dp[i - 1][1] + dif[i - 1][0][1]);
			dp[i][1] = min(dp[i - 1][1] + dif[i - 1][1][1], dp[i - 1][0] + dif[i - 1][0][0]);
		}

		cout << min(dp[n - 1][0] + s1, dp[n - 1][1] + s2) << '\n';

	}
}
#include <iostream>
#include <algorithm>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int dp[100001];

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> vec;

	fill(dp, dp + 10001, -1);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		dp[temp] = 1;
		vec.push_back(temp);
	}

	for (int i = 1; i <= k; i++) {
		if (dp[i] == -1) dp[i] = 999999;
		for (auto& el : vec) {
			if (i <= el) continue;
			if (dp[i - el] == -1) continue;
			dp[i] = min(dp[i], dp[i - el] + 1);
		}
		if (dp[i] == 999999) dp[i] = -1;
	}

	cout << dp[k];
}
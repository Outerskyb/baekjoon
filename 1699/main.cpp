#include <iostream>
#include <vector>
#include <cmath>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

vector<int> square;
int dp[100001];

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= 100000; i++) {
		if (sqrt(i) == (int)sqrt(i)) square.push_back(i), dp[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i] == 0) dp[i] = 100001;
		for (const auto& el : square) {
			if (i < el) break;
			dp[i] = min(dp[i], dp[i - el] + 1);
		}
		if (dp[i] == 100001) dp[i] = 0;
	}
	
	cout << dp[n];
}


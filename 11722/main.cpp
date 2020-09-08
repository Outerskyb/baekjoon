#include <iostream>

using namespace std;

int n;
int arr[1000], dp[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; dp[i] = 1;
	}

	int M = dp[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		M = (M > dp[i]) ? M : dp[i];
	}

	cout << M;
}
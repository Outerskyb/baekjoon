#include <iostream>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<double> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	double dp[10000];
	double M = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (j == i) dp[j] = vec[j];
			else dp[j] = dp[j - 1] * vec[j];
			M = max(M, dp[j]);
		}
	}
	printf("%.3f", M);
}

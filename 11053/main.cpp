#include <iostream>
#include <cinttypes>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[1000][1000];
vector<int> vec;

int f(int n, int min) 
{
	if (n == 0) return dp[1][min];
	int& ret = dp[n][min];
	if (ret != -1) return ret;
	
	if (vec[n] > min) ret = f(n - 1, min);
	else ret = max(f(n - 1, min), f(n - 1, vec[n]));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vec = vector<int>(n);

	for (int i = 0; i < n; i++) cin >> vec[i];
	memset(dp, -1, sizeof dp);

}
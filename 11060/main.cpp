#include <iostream>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int n;
int map[1001];
int dp[1001];


int main()
{
	memset(dp,127 , 4 * 1001);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= map[i]; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	
	cout << ((dp[n - 1]== 2139062143)? -1:dp[n-1]);
}
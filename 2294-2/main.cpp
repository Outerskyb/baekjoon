#include <iostream>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))
#define mo(a,b) ((a==-1)?(-1):(a+b))

using namespace std;

int coin[100];
int dp[10001];
int n;

int func(int rest) {
	if (dp[rest] != -1) return dp[rest];
	if (rest == 0) return 0;

	for (int i = 0; i < n; i++) {
		if (rest - coin[i] >= 0) dp[rest] = ((dp[rest] == -1) ? mo(func(rest - coin[i]) , 1) : min(dp[rest], mo(func(rest - coin[i]) , 1)));
	}
	return dp[rest];
}

int main()
{

	int k;

	memset(dp, -1, sizeof dp);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	cout << func(k);

}
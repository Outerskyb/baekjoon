#include <iostream>
#include <cstring>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;
	if (a > 20 or b > 20 or c > 20)
		return w(20, 20, 20);
	if (dp[a][b][c] != -1) return dp[a][b][c];
	if (a < b and b < c)
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	memset(dp, -1, sizeof dp);
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 and b == -1 and c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}
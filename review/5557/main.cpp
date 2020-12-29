#include <iostream>
#include <cstring>
#include <cinttypes>

using namespace std;

int input[101];
int64_t dp[101][21];

int64_t func(int l, int v) {
    if (dp[l][v] != 0) return dp[l][v];
    if (l > 0 && v - input[l] >= 0) dp[l][v] += func(l - 1, v - input[l]);
    if (l > 0 && v + input[l] < 21) dp[l][v] += func(l - 1, v + input[l]);
    return dp[l][v];
}
int main()
{
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    dp[0][input[0]] = 1;
    cout << func(n - 2, input[n - 1]);
}
#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
    int n;
    cin >> n;
    uint64_t dp[51] = { 1,1,3 };
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007 + 1) % 1000000007;
    cout << dp[n];
}
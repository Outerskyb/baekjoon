#include <iostream>
#include <cinttypes>

using namespace std;

int main()
{
    uint64_t dp[116] = { 1,1,1,2,3 };
    for (int i = 5; i < 116; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    int n;
    cin >> n;
    cout << dp[n-1];
}
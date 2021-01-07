#include <iostream>
#include <cinttypes>

using namespace std;

uint64_t dp[1000001] = {0, 1,2,4 };
int main()
{
    for (int i = 4; i < 1000001; i++) {
        dp[i] = (dp[i - 1] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 3] % 1000000009) % 1000000009;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n]<<'\n';
    }
}
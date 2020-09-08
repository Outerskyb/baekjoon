#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][10];

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += dp[i - 1][j];
            dp[i][j] = (dp[i][j] % 10007 + sum % 10007);
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans % 10007 + dp[n][i] % 10007) % 10007;
    cout << ans;
}
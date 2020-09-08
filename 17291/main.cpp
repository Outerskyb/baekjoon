#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[21] = { 0, 1, 2, 4, 7,14 };
    int ne[21] =  { 0, 1, 1, 2, 4 ,7};
    for (int i = 5; i <= n; i++) {
        dp[i] = dp[i - 1] * 2 - (!(i % 2) ? ne[i - 3] + ne[i - 4] : 0);
        ne[i] = dp[i - 1];
    }

    cout << dp[n];
}
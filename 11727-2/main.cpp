#include <iostream>
#include <cstring>

using namespace std;

int dp[1001];

int func(int n) 
{
    if (dp[n] != -1) return dp[n];
    if (n == 2) return 3;
    if (n == 1) return 1;

    return dp[n] = (func(n - 1)%10007 + 2 * func(n - 2)%10007)%10007;
}

int main() 
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << func(n);
}
#include <iostream>
#include <cstring>
#include <cmath>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int dp[100001];

int func(int n) 
{
    if (dp[n] != -1) return dp[n];
    if (n == 1) return dp[1] = 1;
    if (n <= 0) return dp[0] = 0;

    dp[n] = func(n - 1) + 1;
    for (int i = 2; i <= sqrt(n); i++) {
        dp[n] = min(dp[n],func(n - i * i) + 1);
    }
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << func(n);
}
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    long long dp[1000000];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 2] % 1000000000 + dp[i / 2] % 1000000000) % 1000000000;
    }
    cout << dp[n];
}

/*
 1 1
    1
 2 2
    1 1
    2
 3 2
    1 1 1
    1 2
 4 4 
    1 1 1 1 
    1 1 2
    2 2
    4
5 4
    1 1 1 1 1
    1 1 1 2
    1 2 2 
    1 4
6 6
    1 1 1 1 1 1
    1 1 1 1 2
    1 1 2 2
    2 2 2
    1 1 4
    2 4
7 6
    1 1 1 1 1 1 1
    1 1 1 1 1 2
    1 1 1 2 2
    1 2 2 2
    1 1 1 4
    1 2 4
8 10
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 2
    1 1 1 1 2 2
    1 1 2 2 2
    2 2 2 2
    1 1 1 1 4
    1 1 2 4
    2 2 4
    4 4
    8
*/

#include <iostream>
#include <cstring>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int coin[101];
int dp[10001];
int n, k;

int func(int k)
{
    if (k <= 0)
        return 0;

    if (dp[k] != -1)
        return dp[k];

    for(int i = 0 ; i < n;i++)
        dp[k] = max(dp[k],func(k-coin[i])+1);

    return dp[k];
}

int main()
{
    memset(dp,-1,sizeof dp);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> coin[i];
    }
    cout << func(k);
}
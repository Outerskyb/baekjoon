#include <iostream>
#include <cstring>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int coin[101];
int dp[10001];
int n, k;

int main()
{
    memset(dp,0,sizeof dp);
    dp[0] = 1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> coin[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j<= k;j++){
            if(j-coin[i]>=0)
                dp[j] += dp[j-coin[i]];
        }
    }
    cout << dp[k];
}
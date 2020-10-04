#include "bits/stdc++.h"

#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main()
{
    int h,y;
    cin >> h>>y;

    int dp[11]={0,};
    dp[0] = h;

    for(int i = 1; i < 11;i++){
        dp[i] = max(dp[i],dp[i-1] + dp[i-1]*0.05f);
        if(i>2) dp[i] = max(dp[i],dp[i-3]+dp[i-3]*0.2f);
        if(i>4) dp[i] = max(dp[i],dp[i-5]+dp[i-5]*0.35f);
    }
    cout << (int)dp[y];
}
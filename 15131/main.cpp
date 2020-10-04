#include "bits/stdc++.h"

using namespace std;

//0 1 2 3 4 5 6 7 8 9
//6 2 5 5 4 5 6 3 7 6

//0 1 2 3 4 5 6 7
//0 0 1 7 0 4 5 9 8

int mn[8]={0,0,1,7,4,5,9,8};

int main()
{
    int n;
    cin >> n;
    int dp[1000001]={0,};

    for(int i = 1 ; i <=n;i++){
        for(int j = 2; j < 8;j++){
            if(i<j) break;
            if(dp[i] ==0) dp[i] = mn[j];
            if(i-j!=1)
                dp[i] = max(dp[i],dp[i-j] +mn[j]);
        }
    }
    cout <<dp[n];
}
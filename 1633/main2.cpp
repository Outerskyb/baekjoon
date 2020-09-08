#include <iostream>
#include <cstring>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int cnt;
int w[1000], b[1000];
int dp[1000][15][15];

int func(int n, int lw, int lb)
{
    if (dp[n][lw][lb] != -1)
        return dp[n][lw][lb];
    if (n >= cnt)
        return 0;

    dp[n][lw][lb] = func(n + 1, lw, lb);

    if (lw > 0)
        dp[n][lw][lb] = max(dp[n][lw][lb], func(n + 1, lw - 1, lb) + w[n]);
    if (lb > 0)
        dp[n][lw][lb] = max(dp[n][lw][lb], func(n + 1, lw, lb - 1) + b[n]);
    
    return dp[n][lw][lb];
}

int main()
{
    memset(dp,-1,sizeof dp);
    int x, y;
    while (scanf("%d %d", &w[cnt], &b[cnt++]) != EOF);

    cout << func(0,15,15);
}
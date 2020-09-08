#include <iostream>
#include <cstring>

using namespace std;

int dp[101][101];

int func(int l, int r)
{
    if ((l == 1 && r == 2) || (l == 2 && r == 1))
        return 1;
    if (dp[l][r] != -1) return dp[l][r];
    for (int i = 1; i < l; i++){
        if (!func(i, l - i)){
            return dp[l][r] = 1;
        }
    }
    for (int i = 1; i < r; i++){
        if (!func(i, r - i)){
            return dp[l][r] = 1;
        }
    }
    return dp[l][r] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    int n, m;
    cin >> n >> m;

    cout << (func(n,m) ? 'A' : 'B');
}
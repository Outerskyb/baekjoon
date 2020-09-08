#include <iostream>
#include <cstring>

using namespace std;

int n, s, m;
int dp[101][1001];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s >> m;

    int vols[100];

    for (int i = 0; i < n; i++)
    {
        cin >> vols[i];
    }

    dp[0][s] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j])
            {
                if (j + vols[i] <= m)
                    dp[i + 1][j + vols[i]] = 1;
                if (j - vols[i] >= 0)
                    dp[i + 1][j - vols[i]] = 1;
            }
        }
    }

    int ans = -1;
    for (int i = 0; i <= m; i++)
    {
        if (dp[n][i])
            ans = i;
    }
    cout << ans;
}
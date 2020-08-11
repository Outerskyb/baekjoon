#include <iostream>
#include <cstring>
#include <vector>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, w;
    cin >> t >> w;
    vector<int> vec;
    int dp[1000][31];
    memset(dp, 0, sizeof dp);

    int now, prev, cnt = 1;
    cin >> now;
    prev = now;
    bool parity = now - 1;
    for (int i = 1; i < t; i++)
    {
        cin >> now;
        if (now == prev)
            ++cnt;
        else
        {
            prev = now;
            vec.push_back(cnt);
            cnt = 1;
        }
    }

    vec.push_back(cnt);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = max(0,w-i-1); j <= w; j++)
        {
            if (i != 0)
                dp[i][j] = max(dp[i][j],dp[i - 1][j]);
            if ((i%2) ^ parity == j % 2)
                dp[i][j] += vec[i];
            if (i != 0 && j != w)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + vec[i]);
        }
        //dp[i][w] = max(dp[i][w], dp[i - 1][w]);
    }

    int ans = 0;
    for (int i = 0; i <= w; i++)
    {
        ans = max(ans, dp[vec.size() - 1][i]);
    }
    cout << ans;
}

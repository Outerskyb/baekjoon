#include <iostream>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    s1 = 'a' + s1;
    s2 = 'a' + s2;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int y = s1.size() - 1, x = s2.size() - 1;

    string ans;
    while (dp[y][x]) {
        if (dp[y - 1][x] == dp[y][x]) {
            --y;
            continue;
        }
        if (dp[y][x - 1] == dp[y][x]) {
            --x;
            continue;
        }
        if (dp[y - 1][x - 1] == dp[y][x] - 1) {
            ans.push_back(s1[y]);
            --y, --x;
            
        }
    }
    cout << ans.size()<<'\n';
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it;
}
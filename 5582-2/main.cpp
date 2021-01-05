#include <iostream>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[4001][4001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    s1 = 'a' + s1;
    s2 = 'b' + s2;
    int ans = 0;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j] && s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if (s1[i] == s2[j])
                dp[i][j] = 1;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}
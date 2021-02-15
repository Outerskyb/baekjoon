#include <iostream>
#include <vector>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;
int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string s, t;
    cin >> n >> s;

    cin >> m >> t;
    s = 'a' + s;
    t = 'b' + t;

    int M = 0, cy, cx;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 1; j < t.size(); j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 3;
                if (dp[i][j] > M) M = dp[i][j], cy = i, cx = j;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 2;
            if (dp[i][j] < 0) dp[i][j] = 0;
        }
    }
    //max Ã£¾Æ¼­

    vector<int> vs, vt;
    while (dp[cy][cx] != 0) {
        if (dp[cy - 1][cx - 1] + 3 == dp[cy][cx] && s[cy] == t[cx]) {
            vs.push_back(cy), vt.push_back(cx);
            --cx, --cy;
            continue;
        }
        if (dp[cy][cx - 1] - 2 == dp[cy][cx]) {
            --cx;
            continue;
        }
        if (dp[cy - 1][cx] - 2 == dp[cy][cx]) {
            --cy;
            continue;
        }
    }

    cout << M << '\n';

    for (int i = vs.back(); i <= vs.front(); i++)
        cout << s[i];
    cout << '\n';
    for (int i = vt.back(); i <= vt.front(); i++)
        cout << t[i];
}
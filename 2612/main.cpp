#include <iostream>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    string s1, s2;
    cin >> a >> s1 >> b >> s2;

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            if (s1[j] != s2[i-1])
                dp[i][j] = max(max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) - 2, 0);
            else
                dp[i][j] = dp[i-1][j-1]+3;
        }
    }
    int ey, ex,M=0;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            if (dp[i][j] > M)
                ey = i, ex = j,M=dp[i][j];
        }
    }

    int y = ey, x = ex;
    cout << M << '\n';
    while (dp[y][x] != 0) {
        if (y>0&&dp[y - 1][x] == dp[y][x] + 2)
            y--;
        else if (x>0&&dp[y][x - 1] == dp[y][x] + 2)
            x--;
        else
            y--, x--;
    }

    cout << s1.substr(x, ex - x)<<'\n'<<s2.substr(y-1,ey-y-1);
    
}
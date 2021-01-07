#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[100][10001];

int main()
{
    int n, m;
    cin >> n >> m;
    int a[100],c[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> c[i];
    
    dp[0][c[0]] = a[0];
 
    int mj = (a[0] >= m)?c[0]:100000;
    for (int i = 1; i < n; i++) {
        for (int j = 10000; j >= 0; j--) {
            if (j >= c[i])
                dp[i][j] = max(dp[i][j] + dp[i - 1][j - c[i]] + a[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
            if (dp[i][j] >= m) {
                if (j < mj) mj = j;
            }
        }
    }

    cout << mj;
}
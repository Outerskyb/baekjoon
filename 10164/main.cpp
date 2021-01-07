#include <iostream>


using namespace std;

int dp[16][16];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int y, x;
    if (c == 0) {
        cout << dp[a - 1][b - 1]; return 0;
    }
    if (c % b == 0) { y = b - 1, x = c / b - 1; cout << dp[y][x]; return 0; }
    y = c / b, x = c % b-1;
    cout << dp[y][x] * dp[a - y-1][b - x-1];

}
#include <iostream>
#include <string>

using namespace std;

int dp[4000][4000];
int board[4000][4000];
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) board[i][j] = 1;
        }
    }

    for (int i = str1.size() - 1; i >= 0; i--) {
        for (int j = str2.size() - 1; j >= 0; j--) {
            if (!board[i][j]) dp[i][j] = (dp[i + 1][j] > dp[i][j + 1]) ? dp[i + 1][j] : dp[i][j + 1];
            else dp[i][j] = dp[i + 1][j + 1] + 1;
        }
    }

    cout << dp[0][0];
}
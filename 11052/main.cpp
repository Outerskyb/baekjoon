#include <iostream>
#include <cstring>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[1001];

vector<int> p(1,0);

int func(int n)
{
    if (dp[n] != -1) return dp[n];
    if (n == 1) return p[1];
    if (n <= 0) return 0;

    dp[n] = p[n];
    for (int i = 1; i < n; i++) {
        dp[n] = max(dp[n], func(n - i) + p[i]);
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }
    cout << func(n);
}
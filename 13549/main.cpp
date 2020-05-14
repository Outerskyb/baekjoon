#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int dp[100001];

int main()
{
    for (int i = 0; i < 100001; i++) dp[i] = 987654321;
    int n;
    int k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();       
        if (curr.first > 100000 || curr.first < 0) continue;
        
        if (dp[curr.first] <= curr.second) continue;
        else dp[curr.first] = curr.second;
        
        q.push(make_pair(curr.first - 1, curr.second + 1));
        q.push(make_pair(curr.first + 1, curr.second + 1));
        q.push(make_pair(curr.first * 2, curr.second));
    }
    cout << dp[k];
}

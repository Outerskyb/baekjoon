#include <iostream>
#include <queue>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int mat[1001][1001];
int dp[1001][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        mat[p][q] = r;
    }

    queue<int> q;
    q.push({ 1 });
    bool st = true;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr == 1)
            if (st) st = false;
            else continue;

        for (int i = 1; i <= n; i++) {
            if (mat[curr][i] && dp[curr][0] + mat[curr][i] > dp[i][0]) {
                q.push({ i });
                dp[i][0] = dp[curr][0] + mat[curr][i];
                dp[i][1] = curr;
            }
        }
    }

    cout << dp[1][0] << '\n';
    vector<int> vec;
    int curr = 1;
    while (dp[curr][1] != 1) {
        vec.push_back(dp[curr][1]);
        curr = dp[curr][1];
    }
    cout << 1 << ' ';
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << ' ';
    }
    cout << 1;
}
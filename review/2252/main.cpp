#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n);
    int cnt[32001] = { 0 };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        vec[a].push_back(b);
        cnt[b]++;
    }
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!cnt[i]) q.push(i);
    }

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        cout << curr+1<<' ';
        for (auto& node : vec[curr]) {
            --cnt[node];
            if (cnt[node] == 0) {
                q.push(node);
            }
        }
    }
}
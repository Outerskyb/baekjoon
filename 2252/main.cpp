#include <iostream>
#include <queue>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> al(n);
    int ac[32001] = { 0 };

    for (int i = 0; i < m; i++) {
        int s, d;
        cin >> s >> d;
        --s, --d;
        al[s].push_back(d);
        ac[d]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!ac[i])
            q.push(i);
    }
    while (!q.empty()) {
        auto curr = q.front();
        cout << curr + 1 << ' ';
        q.pop();
        for (const auto& node : al[curr]) {
            --ac[node];
            if (!ac[node])
                q.push(node);
        }
    }
}
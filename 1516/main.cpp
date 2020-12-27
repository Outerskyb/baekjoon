#include <iostream>
#include <queue>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> al(n);
    bool isBranch[501] = { 0, };
    int ac[501] = { 0 };
    int d[501] = { 0 };
    int time[501];
    for (int i = 0; i < n; i++) {
        int t, l;
        cin >> t;
        time[i] = t;
    a:
        cin >> l;
        if (l != -1) {
            al[l-1].push_back(i);
            ac[i]++;
            isBranch[i] = true;
            goto a;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!isBranch[i])
            q.push(i);
    }
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (const auto& node : al[curr]) {
            d[node] = max(d[node], d[curr] + time[curr]);
            --ac[node];
            if(!ac[node])
                q.push(node);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] + time[i] << '\n';
    }
}
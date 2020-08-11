#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct s {
    int pos;
    int depth;
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    bool visit[20000] = {0};
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    int max = 0;
    int max_idx = 0;
    int cnt = 0;

    queue<s> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto el = q.front();
        q.pop();

        if(visit[el.pos]) continue;
        visit[el.pos] = true;
        
        if (el.depth > max) {
            max_idx = el.pos;
            max = el.depth;
            cnt = 1;
        } else if (el.depth == max) {
            max_idx = el.pos < max_idx ? el.pos : max_idx;
            cnt++;
        }

        for (auto hut : vec[el.pos])
            if (!visit[hut])
                q.push({hut, el.depth + 1});
    }
    cout << max_idx << ' ' <<  max<< ' '  << cnt;
}
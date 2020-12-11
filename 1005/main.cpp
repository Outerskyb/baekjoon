#include "bits/stdc++.h"

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, d[1000], w;
        bool is_branch[1000] = {0}, board[1000][1000] = {0};
        int time[1000] = {0};
        int ac[1000] = {0};

        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> d[i];

        queue<int> q;
        for (int i = 0; i < k; i++) {
            int st, dt;
            cin >> st >> dt;
            --st, --dt;
            board[st][dt] = 1;
            is_branch[dt] = true;
            ac[dt]++;
        }
        for (int i = 0; i < n; i++)
            if (!is_branch[i]) q.push(i);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (board[curr][i]) {
                    --ac[i];
                    if (ac[i] == 0)
                        q.push(i);
                }
                if (board[curr][i] && time[i] < time[curr] + d[curr]) {
                    time[i] = time[curr] + d[curr];
                }
            }
        }

        cin >> w;
        --w;
        cout << time[w] + d[w] << '\n';
    }
}
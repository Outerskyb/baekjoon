#include "bits/stdc++.h"

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> vec;
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            q.push({temp, i});
            vec.push_back(temp);
        }
        sort(vec.rbegin(), vec.rend());
        int pr = 0;
        while (!q.empty()) {
            if (q.front().first == vec[pr]) {
                if (q.front().second == M) {
                    cout << pr + 1 << '\n';
                    break;
                }
                q.pop(), pr++;
            } else {
                q.push(q.front());
                q.pop();
            }
        }
    }
}
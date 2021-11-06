#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parents[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    memset(parents, -1, sizeof parents);

    queue<pair<int, int>> que;
    que.push({ N,0 });

    while (!que.empty()) {
        int pos = que.front().first;
        int lev = que.front().second;
        que.pop();

        if (pos == K) {
            cout << lev<<'\n';
            break;
        }

        if (pos - 1 >= 0 && parents[pos - 1] == -1) {
            que.push({ pos - 1,lev + 1 });
            parents[pos - 1] = pos;
        }
        if (pos + 1 <= 100000 && parents[pos + 1] == -1) {
            que.push({ pos + 1,lev + 1 });
            parents[pos + 1] = pos;
        }
        if (pos * 2 <= 100000 && parents[pos * 2] == -1) {
            que.push({ pos * 2,lev + 1 });
            parents[pos * 2] = pos;
        }
    }

    vector<int> route;
    route.push_back(K);
    int curr = K;

    while (curr != N) {
        route.push_back(parents[curr]);
        curr = parents[curr];
    }

    reverse(route.begin(), route.end());

    for (const auto& pos : route) {
        cout << pos << ' ';
    }

    return 0;
}
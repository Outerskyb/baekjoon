#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int p[10001];

int find(int n)
{
    return (p[n] < 0) ? n : p[n] = find(p[n]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return;
    p[b] = a;
}

int main()
{
    memset(p, -1, sizeof p);
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, pair<int, int>>> vec;
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        vec.push_back(make_pair(C, make_pair(A, B)));
    }

    sort(vec.begin(), vec.end());

    int sum = 0;
    for (auto& el : vec)
    {
        if (find(el.second.first) != find(el.second.second)) {
            merge(el.second.first, el.second.second);
            sum += el.first;
        }
    }

    cout << sum;
}

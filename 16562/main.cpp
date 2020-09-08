#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int p[10001];
int price[10001];

int find(int n)
{
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

int size(int n)
{
    if (p[n] < 0) return p[n] * -1;
    return size(p[n]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return;
    p[a] += p[b];
    p[b] = a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(p, -1, sizeof p);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int cp;
        cin >> cp;
        price[i] = cp;
    }

    for (int i = 0; i < m; i++)
    {
        int v, w;
        cin >> v >> w;
        merge(v - 1, w - 1);
    }

    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[find(i)].push_back(price[i]);
    }
    int sum = 0;
    for (auto& v : vec) {
        auto it = min_element(v.begin(), v.end());
        sum += (it == v.end()) ? 0 : *it;
    }
    if (sum <= k)cout << sum;
    else cout << "Oh no";

}
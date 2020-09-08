#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int p[200001];

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int m, n;
po:
    cin >> m >> n;
    if (m == 0) return 0;
   
    memset(p, -1, sizeof p);
    priority_queue<pair<int, pair<int, int>>> pq;

    int ssum = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pq.push(make_pair(-z, make_pair(x, y)));
        ssum += z;
    }

    int sum = 0;
    while (!pq.empty())
    {
        auto el = pq.top();
        pq.pop();
        if (find(el.second.second) != find(el.second.first)) {
            merge(el.second.second, el.second.first);
            sum += el.first;
        }
    }
    cout << ssum+sum<<'\n';
     goto po;
}
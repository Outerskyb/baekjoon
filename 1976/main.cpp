#include <iostream>
#include <cstring>

using namespace std;

int p[201];

int find(int n)
{
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b)
{
    if (find(a) == find(b)) return;
    p[find(a)] = find(b);
}

int main()
{
    memset(p, -1, sizeof p);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if (a) merge(i, j);
        }
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        sum += find(a - 1);
    }
    cout << ((sum % m == 0) ? "YES" : "NO");

}
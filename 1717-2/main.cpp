#include <iostream>
#include <cstring>  

using namespace std;

int p[1000001];

int find(int a)
{
    if (p[a] < 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b)
{
    if (find(a) == find(b)) return;
    p[find(b)] = find(a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(p, -1, sizeof p);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 0) {
            merge(a, b);
        }
        else {
            cout << ((find(a) == find(b)) ? "yes\n" : "no\n");
        }
    }

}
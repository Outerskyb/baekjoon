#include <iostream>
#include <cstring>

using namespace std;

int p[500000];

int find(int n) {
    if (p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    p[b] = a;
}

int main()
{
    memset(p, -1, sizeof p);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        if (find(s) == find(e)) {
            cout << i + 1;
            return 0;
        }
        merge(s, e);
    }
    cout << 0;
}
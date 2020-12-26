#include <iostream>
#include <cstring>

using namespace std;

int num[2001];
int pal[2001][2001];

int func(int s, int e) {
    if (pal[s][e] != -1) return pal[s][e];
    if (s == e) return 1;

    if (num[s] == num[e]) {
        if (s + 1 == e) return pal[s][e] = 1;
        return pal[s][e] = func(s + 1, e - 1);
    }
    else {
        return pal[s][e] = 0;
    }
}

int main()
{
    memset(pal, -1, sizeof pal);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << func(s-1,e-1)<<'\n';
    }
}
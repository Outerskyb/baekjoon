#include <iostream>
#include <cinttypes>

using namespace std;

int s = 1;
int64_t t[262145];

void update(int pos, int val)
{
    pos += s;
    t[pos] = val;
    while (pos > 1) {
        pos /= 2;
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
}

void build()
{
    for (int i = s-1; i >= 1; i--) {
        t[i] = t[i * 2] + t[i * 2+1];
    }
}

int64_t sum(int L, int R, int nN, int nL, int nR)
{
    if (nR<L || nL>R) return 0;
    if (nL >= L && nR <= R) return t[nN];

    int mid = (nL + nR) / 2;
    return sum(L, R, nN * 2, nL, mid) + sum(L, R, nN * 2 + 1, mid + 1, nR);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    while (s < n) s *= 2;
    for (int i = 0; i < n; i++) {
        cin >> t[i + s];
    }
    build();
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a>b) a ^= b, b ^= a, a ^= b;
        cout << sum(a - 1, b - 1, 1, 0, s - 1) << '\n';
        update(c-1, d);
    }
}
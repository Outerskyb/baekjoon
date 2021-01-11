#include <iostream>
#include <cinttypes>

using namespace std;

int n, m, s = 1;
int64_t t[2097152];

void update(int pos, int val) {
    pos += s;
    t[pos] = val;
    while (pos > 1) {
        pos /= 2;
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
}

int64_t sum(int L, int R, int nN, int nL, int nR) {
    if (nL>R || nR<L) return 0;
    if (L <= nL && nR <= R) return t[nN];
    int mid = (nL + nR) / 2;
    return sum(L, R, nN * 2, nL, mid) + sum(L, R, nN * 2 + 1, mid + 1, nR);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (s < n) s *= 2;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a) {
            update(b - 1, c );
        }
        else {
            if (b > c) b ^= c, c ^= b, b ^= c;
            cout <<sum(b - 1, c - 1, 1, 0, s - 1)<<'\n';
        }
    }
}
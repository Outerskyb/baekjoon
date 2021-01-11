#include <iostream>
#include <cinttypes>

using namespace std;

int s = 1;
int64_t t[2097153];

void update(int pos, int val)
{
    pos += s;
    t[pos] += val;
    while (pos > 1) {
        pos /= 2;
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
}

int64_t sum(int L, int R, int nN, int nL, int nR)
{
    if (L > nR || R < nL) return 0;
    if (L <= nL && R >= nR) return t[nN];
    int mid = (nL + nR) / 2;
    return sum(L, R, nN * 2, nL, mid) + sum(L, R, nN * 2 + 1, mid + 1, nR);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    while (s < N) s *= 2;

    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b - 1, c);
        else
            cout << sum(b - 1, c - 1, 1, 0, s - 1) << '\n';
    }
}
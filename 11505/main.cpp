#include <iostream>
#include <cinttypes>

using namespace std;

int s, n, m, k;

int64_t t[2097152];

void update(int pos, int num) {
    pos += s;
    t[pos] = num;
    while (pos > 1) {
        pos /= 2;
        t[pos] = ((t[pos * 2] % 1000000007) * (t[pos * 2 + 1] % 1000000007)) % 1000000007;
    }
}

int64_t mul(int L, int  R, int nodeNum, int nodeL, int nodeR) {
    if (L > nodeR || R < nodeL) return 1;
    if (L <= nodeL && R >= nodeR) return t[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return ((mul(L, R, nodeNum * 2, nodeL, mid) % 1000000007) * (mul(L, R, nodeNum * 2 + 1, mid + 1, nodeR) % 1000000007)) % 1000000007;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    s = 1;
    while (s < n) s *= 2;
    for (int i = 0; i < 2*s; i++)t[i] = 1;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        update(i, temp);
    }

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b-1, c);
        else
            cout << mul(b-1, c-1,1,0,s-1) << '\n';
    }
}
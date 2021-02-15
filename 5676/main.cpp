#include <iostream>

using namespace std;

int t[262145], s = 1;
char code[] = { '-','0','+' };
int sim(int num) {
    if (num < 0) return -1;
    return (num > 0);
}

void update(int pos, int val) {
    pos += s;
    t[pos] = val;
    while (pos > 1) {
        pos /= 2;
        t[pos] = t[pos * 2] * t[pos * 2 + 1];
    }
}

int mul(int L, int R, int nN, int nL, int nR) {
    if (nR < L || R < nL) return 1;
    if (L <= nL && nR <= R) return t[nN];
    int mid = (nL + nR) / 2;
    return mul(L, R, nN * 2, nL, mid) * mul(L, R, nN * 2 + 1, mid + 1, nR);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,  k;
    while (cin >> n >> k) {
        s = 1;
        while (s < n) s *= 2;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            update(i, sim(x));
        }
        for (int i = 0; i < k; i++) {
            char a; int b, c;
            cin >> a >> b >> c;
            if (a == 'C')
                update(b - 1, sim(c));
            else
                cout << code[mul(b - 1, c - 1, 1, 0, s - 1) + 1] ;
        }
        cout << '\n';
    }
}
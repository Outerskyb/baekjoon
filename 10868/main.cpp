#include <iostream>

using namespace std;

int s = 1;
int t[262145];

int mymin(int a, int b) {
    if (a < b)
        return a;
    return b;
}

void update(int pos, int val) {
    pos += s;
    t[pos] = val;
    while (pos > 1) {
        pos /= 2;
        if (t[pos * 2] < t[pos * 2 + 1]) {
            t[pos] = t[pos * 2];
        }
        else {
            t[pos] = t[pos * 2 + 1];
        }
    }
}

int getMin(int L, int R, int nN, int nL, int nR) {
    if (nL > R || nR < L) return 1000000002;
    if (L <= nL && nR <= R) return t[nN];
    int mid = (nL + nR) / 2;
    return mymin(getMin(L, R, nN * 2, nL, mid), getMin(L, R, nN * 2 + 1, mid + 1, nR));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    while (s < N) s *= 2;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        update(i, temp);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << getMin(a - 1, b - 1, 1, 0, s - 1)<<'\n';
    }
}
#include <iostream>
#include <cinttypes>

using namespace std;

int64_t t[2097152];
int s = 1;
int N, M, K;
void update(int64_t num, int p) {
    p += s;
    int diff = num-t[p];
    t[p] = num;
    while (p > 1) {
        p /= 2;
        t[p] += diff;
    }
}

int64_t sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
    if (R < nodeL || nodeR < L) return 0;
    if (L <= nodeL && nodeR <= R) return t[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid+1, nodeR);
}

int main()
{
    cin >> N >> M >> K;
    
    while (s < N) s *= 2;
    for (int i = 0; i < N; i++) {
        int64_t temp;
        cin >> temp;
        update(temp, i);
    }
    for (int i = 0; i < M + K; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(c, b-1);
        }
        else {
            cout << sum(b-1, c-1, 1, 0, s - 1)<<'\n';
        }

    }
}
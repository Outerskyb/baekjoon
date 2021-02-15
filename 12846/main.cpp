#include <iostream>
#include <cinttypes>

#define min(a,b) (((a)>(b))?(a):(b))

using namespace std;

int s = 1;

int64_t t[262145];

void update(int num, int p) {
    p += s;
    t[p] = num;
    while (p > 1) {
        p /= 2;
        t[p] = min(t[p * 2], t[p * 2 + 1]);
    }
}

uint64_t mini(int nL, int nR, int L, int R, int nN) {
    if (R < nL || nR < L) return 9765432198765;
    if (L <= nL && nR <= R) return t[nN];
    int mid = (nL + nR) / 2;
    return min(mini(L, R, nN * 2, nL, mid) , mini(L, R, nN * 2 + 1, mid + 1, nR));
}

int main()
{
    int n;
    
}